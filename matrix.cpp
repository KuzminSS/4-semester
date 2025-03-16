//
// Created by simen on 14.03.2025.
//
#include "matrix.hpp"

template<class T>
Matrix<T>::Matrix(std::vector<T> const& data, unsigned rows, unsigned cols) : data(data), rows(rows), cols(cols) {
    std::cout << "create Matrix" << std::endl;
}

template<class T>
Matrix<T>::Matrix(unsigned rows, unsigned cols, T value) : rows(rows), cols(cols) {
    data.resize(rows * cols, value);
}

template<class T>
Matrix<T> Matrix<T>::Identity(unsigned rows) {
    std::vector<T> identity;
    identity.resize(rows * rows);
    int j = 0;
    for (unsigned i = 0; i < rows; ++i) {
        identity[i + j * rows] = 1;
        j++;
    }
    return Matrix(identity, rows, rows);
}

template<class T>
Matrix<T> Matrix<T>::getSpecificDeterminantTriangle(unsigned n, T determinant) {
    Matrix<T> new_matrix = Identity(n);
    int randInd = rand() % n;
    new_matrix(randInd, randInd) = determinant;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            new_matrix(i, j) = rand() % 5;
        }
    }
    return new_matrix;
}

template<class T>
Matrix<T> Matrix<T>::getSpecificDeterminant(unsigned n, T determinant) {
    Matrix<T> new_matrix = getSpecificDeterminantTriangle(n, determinant);
    int a, b;
    for (int i = 0; i < n*2; i++) {
        a = rand() % n;
        if (a) {
            b = a/2;
            new_matrix.row_subtraction(a, b, -1);
        }
    }
    return new_matrix;
}

template<class T>
void Matrix<T>::row_subtraction(unsigned b, unsigned a, T mult) {
    for (int i = 0; i < cols; i++) {
        operator()(b, i) -= operator()(a, i)*mult;
    }
}

template<class T>
unsigned int Matrix<T>::get_rows() const {
    return rows;
}

template<class T>
unsigned int Matrix<T>::get_cols() const {
    return cols;
}

template<class T>
Matrix<T>& Matrix<T>::transpose() {
    std::vector<T> temp(rows * cols);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            temp[j * rows + i] = data[i * cols + j];
        }
    }
    std::swap(rows, cols);
    data = temp;
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> transposed(cols, rows);
    transposed.transpose();
    return transposed;
}

template<class T>
T& Matrix<T>::operator()(unsigned row, unsigned col) {
    return data[row * cols + col];
}

template<class T>
T Matrix<T>::operator()(unsigned row, unsigned col) const {
    return data[row * cols + col];
}

template<class T>
Matrix<T> Matrix<T>::permutation() {
    std::vector<T> v;
    std::vector<T> w;
    v.resize(cols);
    w.resize(cols);

    for (int i = 0; i < cols; i++) {
        int x = rand() % (cols - 1);
        int y = rand() % (cols - 1);
        for (int j = x*cols; j < (x+1)*cols; j ++){
            v[j-x*cols] = data[j];
        }
        for (int j = y*cols; j < (y+1)*cols; j ++){
            w[j-y*cols] = data[j];
        }
        for (int j = x*cols; j < (x+1)*cols; j ++){
            data[j] = w[j-x*cols];
        }
        for (int j = y*cols; j < (y+1)*cols; j ++){
            data[j] = v[j-y*cols];
        }
    }
    return *this;
}

template<class T>
T Matrix<T>::Determinant() {
    Gauss();
    return determinant(rows, cols, data);
}

template<class T>
void Matrix<T>::print() const {
    for (int i = 0; i < rows*cols; i++) {
        std::cout << data[i] << " ";
        if ((i+1) % cols == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

template<class T>
Matrix<int> Matrix<T>::Gauss() {
    T mult;
    for (int k = 0; k < rows-1; k++) {
        if (operator()(k, k) > 1e-16 || operator()(k, k) < -(1e-16)) {
            for (int i = k+1; i < rows; i++) {
                mult = operator()(i, k) / operator()(k, k);
                row_subtraction(i, k, mult);
            }
        } else {
            for (int z = k; z < rows; z++) {
                if (operator()(z, k) > 1e-16 || operator()(z, k) < -(1e-16)) {
                    row_subtraction(k, z, -1);
                }
                break;
            }
            if (operator()(k, k) > 1e-16 || operator()(k, k) < -(1e-16)) {
                for (int i = k+1; i < rows; i++) {
                    row_subtraction(i, k, mult);
                }
            }
        }
    }
    return *this;
}

template<class T>
T Matrix<T>::determinant(int rows, int cols, std::vector<T> const& data) {
    int det = data[0];
    int j = 0;
    for (int i = 0; i < cols*rows-cols; ++i) {
        if ((i+1) % cols == 0){
            j++;
            det= det*data[i+1 + j];
        }
    }
    std::cout << "determinant = " << det << std::endl;
    return det;
}

template class Matrix<int>;