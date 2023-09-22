// Copyright 2023 Shuin Evgeniy
#include <gtest/gtest.h>
#include <vector>
#include "../../../modules/task_1/shuin_e_CSR/SparseMatrixCSR.h"

TEST(SparseMatrixCSRTest, test_size_100_200) {
    SparseMatrixCSR matrixA(100, 200, 10);
    SparseMatrixCSR matrixB(200, 100, 20);
    // double timer;
    // timer = omp_get_wtime();
    std::vector<double> result = matrixA * matrixB;
    // timer = omp_get_wtime() - timer;
    // printf("Sequential : %f s\n", timer);
    // timer = omp_get_wtime();
    std::vector<double> result_omp = matrixA.omp_multipliction(matrixB);
    // timer = omp_get_wtime() - timer;
    // printf("OMP : %f s\n", timer);
    ASSERT_EQ(result, result_omp);
}

TEST(SparseMatrixCSRTest, test_size_200_300) {
    SparseMatrixCSR matrixA(200, 300, 10);
    SparseMatrixCSR matrixB(300, 200, 20);
    // double timer;
    // timer = omp_get_wtime();
    std::vector<double> result = matrixA * matrixB;
    // timer = omp_get_wtime() - timer;
    // printf("Sequential : %f s\n", timer);
    // timer = omp_get_wtime();
    std::vector<double> result_omp = matrixA.omp_multipliction(matrixB);
    // timer = omp_get_wtime() - timer;
    // printf("OMP : %f s\n", timer);
    ASSERT_EQ(result, result_omp);
}

TEST(SparseMatrixCSRTest, test_size_435_330) {
    SparseMatrixCSR matrixA(435, 330, 10);
    SparseMatrixCSR matrixB(330, 435, 20);
    // double timer;
    // timer = omp_get_wtime();
    std::vector<double> result = matrixA * matrixB;
    // timer = omp_get_wtime() - timer;
    // printf("Sequential : %f s\n", timer);
    // timer = omp_get_wtime();
    std::vector<double> result_omp = matrixA.omp_multipliction(matrixB);
    // timer = omp_get_wtime() - timer;
    // printf("OMP : %f s\n", timer);
    ASSERT_EQ(result, result_omp);
}

TEST(SparseMatrixCSRTest, test_size_250_160) {
    SparseMatrixCSR matrixA(250, 160, 10);
    SparseMatrixCSR matrixB(160, 400, 20);
    // double timer;
    // timer = omp_get_wtime();
    std::vector<double> result = matrixA * matrixB;
    // timer = omp_get_wtime() - timer;
    // printf("Sequential : %f s\n", timer);
    // timer = omp_get_wtime();
    std::vector<double> result_omp = matrixA.omp_multipliction(matrixB);
    // timer = omp_get_wtime() - timer;
    // printf("OMP : %f s\n", timer);
    ASSERT_EQ(result, result_omp);
}

TEST(SparseMatrixCSRTest, test_size_400_400) {
    SparseMatrixCSR matrixA(400, 400, 10);
    SparseMatrixCSR matrixB(400, 400, 20);
    // double timer;
    // timer = omp_get_wtime();
    std::vector<double> result = matrixA * matrixB;
    // timer = omp_get_wtime() - timer;
    // printf("Sequential : %f s\n", timer);
    // timer = omp_get_wtime();
    std::vector<double> result_omp = matrixA.omp_multipliction(matrixB);
    // timer = omp_get_wtime() - timer;
    // printf("OMP : %f s\n", timer);
    ASSERT_EQ(result, result_omp);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
