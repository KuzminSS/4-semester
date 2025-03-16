//
// Created by simen on 14.03.2025.
//
#include "C:\Users\simen\CLionProjects\untitled1\matrix.hpp"
#include <cassert>

void test_transpose() {
    Matrix<int> m(2, 3);
    m(0, 0) = 1; m(0, 1) = 2; m(0, 2) = 3;
    m(1, 0) = 4; m(1, 1) = 5; m(1, 2) = 6;

    Matrix<int> transposed = m.transpose();
    assert(transposed(0, 0) == 1);
    assert(transposed(1, 0) == 2);
    assert(transposed(2, 0) == 3);
    assert(transposed(0, 1) == 4);
    assert(transposed(1, 1) == 5);
    assert(transposed(2, 1) == 6);
    std::cout << "Test 2 passed: Transpose is correct." << std::endl;
}

int main() {
    test_transpose();
    return 0;
}