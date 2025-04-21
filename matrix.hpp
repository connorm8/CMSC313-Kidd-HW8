// matrix.h

#ifndef matrix_hpp
#define matrix_hpp

#include <vector>
#include <iostream>

class Matrix{
    private:
        std::vector<std::vector<int>> data;
        int rows, cols;

    public:
        Matrix(int rows, int cols); // constructor
        Matrix(const std::vector<std::vector<int>>& values);

        int getRows() const;
        int getCols() const;
        int getValue(int row, int col) const;

        Matrix operator+(const Matrix& other) const; // addition
        Matrix operator*(const Matrix& other) const; // multiplication
        Matrix operator*(int scalar) const; // scalar
        Matrix transpose() const; // transpose

        void print() const; // print
};

#endif 