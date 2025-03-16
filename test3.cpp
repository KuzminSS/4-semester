//
// Created by simen on 14.03.2025.
//
#include "C:\Users\simen\CLionProjects\untitled1\matrix.hpp"
#include <cassert>

void test_gauss() {
    Matrix<int> m(3, 3);
    m(0, 0) = 2; m(0, 1) = 1; m(0, 2) = -1;
    m(1, 0) = -3; m(1, 1) = -1; m(1, 2) = 2;
    m(2, 0) = -2; m(2, 1) = 1; m(2, 2) = 2;

    m.Gauss();
    assert(m(0, 0) == 2);
    assert(m(1, 1) == 0.5);
    assert(m(2, 2) == -1);
    std::cout << "Test 3 passed: Gauss elimination is correct." << std::endl;
}

int main() {
    test_gauss();
    return 0;
}