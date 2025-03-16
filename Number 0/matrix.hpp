#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <cstdlib>
#include <iostream>

template<class T>
class Matrix {
    std::vector<T> data;
    unsigned int cols, rows;

    T determinant(int rows, int cols, std::vector<T> const& data);

public:
    Matrix(std::vector<T> const& data, unsigned rows, unsigned cols);
    Matrix(unsigned rows, unsigned cols, T value = 0);

    static Matrix Identity(unsigned rows);
    static Matrix getSpecificDeterminantTriangle(unsigned n, T determinant);
    static Matrix getSpecificDeterminant(unsigned n, T determinant);

    void row_subtraction(unsigned b, unsigned a, T mult);
    unsigned int get_rows() const;
    unsigned int get_cols() const;

    Matrix& transpose();
    Matrix transpose() const;

    T& operator()(unsigned row, unsigned col);
    T operator()(unsigned row, unsigned col) const;

    Matrix permutation();
    T Determinant();
    void print() const;

    Matrix<int> Gauss();
};

#endif // MATRIX_HPP
