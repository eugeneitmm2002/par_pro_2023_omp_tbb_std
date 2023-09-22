// Copyright 2023 Shuin Evgeniy
#ifndef MODULES_TASK_2_SHUIN_E_CSR_SPARSEMATRIXCSR_H_
#define MODULES_TASK_2_SHUIN_E_CSR_SPARSEMATRIXCSR_H_

#include <omp.h>
#include <vector>
#include <cstdlib>
#include <ctime>

class SparseMatrixCSR {
 public:
    SparseMatrixCSR(const std::vector<double>& matrix, int rows, int cols);

    SparseMatrixCSR(int rows, int cols, int density);

    std::vector<double> operator*(const SparseMatrixCSR& other);

    std::vector<double> omp_multipliction(const SparseMatrixCSR& right);


 private:
    int rows_;
    int cols_;
    std::vector<double> values_;
    std::vector<int> col_indices_;
    std::vector<int> row_ptrs_;

    void ConvertToCSR(const std::vector<double>& matrix);
    SparseMatrixCSR getTranspose() const;
};

#endif  // MODULES_TASK_2_SHUIN_E_CSR_SPARSEMATRIXCSR_H_
