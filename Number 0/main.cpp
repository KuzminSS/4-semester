#include "matrix.hpp"

int main() {
    std::cout << "{{{" << std::endl;
    Matrix<int> m1 = Matrix<int>::getSpecificDeterminant(2, 0);
    m1.print();
    m1.Determinant();
    Matrix<int> m4 = Matrix<int>::getSpecificDeterminant(2, 33);
    m4.print();
    m4.Gauss();
    m4.print();
    m4.transpose();
    m4.print();
    Matrix<int> m2(4, 5);
    m2.print();
    std::cout << "]]]]" << std::endl;
    Matrix<int> m3 = Matrix<int> ::Identity(5);
    m3.print();

    std::cout << m3.Determinant()<< std::endl;

    return 0;
}
