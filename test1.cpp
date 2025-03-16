//
// Created by simen on 14.03.2025.
//
#include "C:\Users\simen\CLionProjects\untitled1\matrix.hpp"
#include <cassert>

void test_identity_matrix() {
    Matrix<int> m = Matrix<int>::Identity(3);
    assert(m(0, 0) == 1);
    assert(m(1, 1) == 1);
    assert(m(2, 2) == 1);
    assert(m(0, 1) == 0);
    assert(m(1, 0) == 0);
    std::cout << "Test 1 passed: Identity matrix is correct." << std::endl;
}

int main() {
    test_identity_matrix();
    return 0;
}