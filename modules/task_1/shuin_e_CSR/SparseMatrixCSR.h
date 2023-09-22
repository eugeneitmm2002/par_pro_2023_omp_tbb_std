// Copyright 2023 Shuin Evgeniy
#ifndef MODULES_TASK_1_SHUIN_E_CSR_SPARSEMATRIXCSR_H_
#define MODULES_TASK_1_SHUIN_E_CSR_SPARSEMATRIXCSR_H_

#include <vector>
#include <cstdlib>
#include <ctime>

class SparseMatrixCSR {
 public:
    SparseMatrixCSR(const std::vector<double>& matrix, int rows, int cols);

    SparseMatrixCSR(int rows, int cols, int density);


    std::vector<double> operator*(const SparseMatrixCSR& other);

 private:
    int rows_;
    int cols_;
    std::vector<double> values_;
    std::vector<int> col_indices_;
    std::vector<int> row_ptrs_;

    // Private helper method to convert a dense matrix to CSR format.
    void ConvertToCSR(const std::vector<double>& matrix);
    SparseMatrixCSR getTranspose() const;
};

#endif  // MODULES_TASK_1_SHUIN_E_CSR_SPARSEMATRIXCSR_H_
