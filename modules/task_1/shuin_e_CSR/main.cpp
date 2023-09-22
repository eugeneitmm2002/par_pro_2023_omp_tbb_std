// Copyright 2023 Shuin Evgeniy
#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include "../../../modules/task_1/shuin_e_CSR/SparseMatrixCSR.h"

TEST(SparseMatrixCSRTest, MultiplicationValid) {
    SparseMatrixCSR matrixA({ 1.0, 2.0, 0.0, 3.0, 0.0, 4.0 }, 2, 3);
    SparseMatrixCSR matrixB({ 0.0, 2.0, 0.0, 1.0, 3.0, 0.0 }, 3, 2);

    std::vector<double> result = matrixA * matrixB;

    std::vector<double> expected_result = { 0.0, 4.0, 12.0, 6.0 };
    ASSERT_EQ(result, expected_result);
}

TEST(SparseMatrixCSRTest, MultiplicationInvalidDimensions) {
    SparseMatrixCSR matrixA({ 1.0, 2.0, 0.0, 3.0, 0.0, 0.0 }, 2, 3);
    SparseMatrixCSR matrixB({ 0.0, 2.0, 0.0, 1.0 }, 2, 2);

    ASSERT_ANY_THROW(matrixA * matrixB);
}

TEST(SparseMatrixCSRTest, MultiplicationAllZeros) {
    SparseMatrixCSR matrixA({ 0.0, 0.0, 0.0, 0.0 }, 2, 2);
    SparseMatrixCSR matrixB({ 0.0, 0.0, 0.0, 0.0 }, 2, 2);

    std::vector<double> result = matrixA * matrixB;

    std::vector<double> expected_result = { 0.0, 0.0, 0.0, 0.0 };
    ASSERT_EQ(result, expected_result);
}

TEST(SparseMatrixCSRTest, MultiplicationLargeMatrices) {
    SparseMatrixCSR matrixA(100, 50, 20);
    SparseMatrixCSR matrixB(50, 200, 15);

    std::vector<double> result = matrixA * matrixB;

    ASSERT_EQ(result.size(), 100 * 200);
}

TEST(SparseMatrixCSRTest, MultiplicationIdentityMatrix) {
    std::vector<double> matrix = { 1.0, 2.0, 0.0, 3.0 };
    SparseMatrixCSR matrixA(matrix , 2, 2);

    SparseMatrixCSR identity({ 1.0, 0.0, 0.0, 1.0 }, 2, 2);

    std::vector<double> result = matrixA * identity;

    ASSERT_EQ(result, matrix);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
