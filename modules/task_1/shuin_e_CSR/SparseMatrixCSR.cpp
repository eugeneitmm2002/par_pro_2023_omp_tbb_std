// Copyright 2023 Shuin Evgeniy
#include "../../../modules/task_1/shuin_e_CSR/SparseMatrixCSR.h"

SparseMatrixCSR::SparseMatrixCSR(const std::vector<double>& matrix,
int rows, int cols)
    : rows_(rows), cols_(cols) {
    ConvertToCSR(matrix);
}

SparseMatrixCSR::SparseMatrixCSR(int rows, int cols, int density)
    : rows_(rows), cols_(cols) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<double> matrix(rows * cols, 0.0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (std::rand() % 100 < density) {
                matrix[i * cols + j] = static_cast<double>(std::rand() % 10);
            }
        }
    }

    ConvertToCSR(matrix);
}

void SparseMatrixCSR::ConvertToCSR(const std::vector<double>& matrix) {
    int nnz = 0;
    row_ptrs_.push_back(0);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            double value = matrix[i * cols_ + j];
            if (value != 0.0) {
                values_.push_back(value);
                col_indices_.push_back(j);
                nnz++;
            }
        }
        row_ptrs_.push_back(nnz);
    }
}

std::vector<double> SparseMatrixCSR::operator*(const SparseMatrixCSR& right) {
    if (cols_ != right.rows_)
        throw "Invalid operation!";

    SparseMatrixCSR rightTranspose = right.getTranspose();

    std::vector <double> result(rows_ * right.cols_, 0.0);

    for (int i = 0; i < rows_; i++)
        for (int j = row_ptrs_[i]; j < row_ptrs_[i + 1]; j++) {
            int col_index = col_indices_[j];
            double Avalue = values_[j];
            for (int k = 0; k < rightTranspose.rows_; k++) {
                double sum = 0.0;
                for (int l = rightTranspose.row_ptrs_[k]
                 ; l < rightTranspose.row_ptrs_[k + 1]; l++)
                    if (col_index == rightTranspose.col_indices_[l]) {
                        sum += Avalue * rightTranspose.values_[l];
                        break;
                    }
                if (sum != 0.0) {
                    result[i * rightTranspose.rows_ + k] += sum;
                }
            }
        }
    return result;
}

SparseMatrixCSR SparseMatrixCSR::getTranspose() const {
    SparseMatrixCSR result(std::vector<double>(), 0, 0);

    result.values_ = std::vector<double>(values_.size(), 0.0);
    result.row_ptrs_ = std::vector<int>(cols_ + 2, 0);
    result.col_indices_ = std::vector<int>(values_.size(), 0);
    result.rows_ = cols_;
    result.cols_ = rows_;

    for (size_t i = 0; i < values_.size(); ++i) {
        ++result.row_ptrs_[col_indices_[i] + 2];
    }

    for (size_t i = 2; i < result.row_ptrs_.size(); ++i) {
        result.row_ptrs_[i] += result.row_ptrs_[i - 1];
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = row_ptrs_[i]; j < row_ptrs_[i + 1]; ++j) {
            const int new_index = result.row_ptrs_[col_indices_[j] + 1]++;
            result.values_[new_index] = values_[j];
            result.col_indices_[new_index] = i;
        }
    }

    result.row_ptrs_.pop_back();


    return result;
}
