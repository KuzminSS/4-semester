#include "matrix.hpp"
#include <cassert>

void test_gauss() {
    Matrix<int> m(3, 3);
    m(0, 0) = 2;
    m(0, 1) = 1;
    m(0, 2) = -1;
    m(1, 0) = 0;
    m(1, 1) = -1;
    m(1, 2) = 2;
    m(2, 0) = -2;
    m(2, 1) = 1;
    m(2, 2) = 2;

    m.Gauss();

    // Проверяем, что ниже главной диагонали нули
    assert(m(1, 0) == 0);
    assert(m(2, 0) == 0);
    assert(m(2, 1) == 0);

    std::cout << "Test 3 passed: Gauss elimination for int produces zeros below diagonal." << std::endl;
}

int main() {
    test_gauss();
    return 0;
}