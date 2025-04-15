// matrix.cpp

#include "matrix.h"
#include <vector>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols){
    data.resize(rows, std::vector<int>(cols, 0));
}

Matrix::Matrix(const std::vector<std::vector<int>>& values)
    : data(values), rows(values.size()), cols(values[0].size()) {}

int Matrix::getRows() const {return rows;}
int Matrix::getCols() const {return cols;}

Matrix Matrix::operator+(const Matrix& other) const{
    Matrix result(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const{
    Matrix result(rows, other.cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < other.cols; j++){
            for(int k = 0; k < cols; k++){
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

Matrix Matrix::operator*(int scalar) const{
    Matrix result(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result.data[i][j] = data[i][j] * scalar;
        }
    }

    return result;
}

Matrix Matrix::transpose() const{
    Matrix result(cols, rows);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result.data[j][i] = data[i][j];
        }
    }

    return result;
}

void Matrix::print() const{
    for (const auto& row : data){
        for(const auto& val : row){
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}