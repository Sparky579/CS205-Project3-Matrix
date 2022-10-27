#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Matrix Matrix;
bool sameSize(const Matrix *mat1, const Matrix *mat2);
float * pos(const Matrix *mat, size_t r, size_t c);
Matrix * createMatrix(size_t rows, size_t columns);
bool deleteMatrix(Matrix **mat);
bool addPosition(Matrix *mat, size_t r, size_t c, float num);
bool substrPosition(Matrix *mat, size_t r, size_t c, float num);
bool setPosition(Matrix *mat, size_t r, size_t c, float num);
bool addScalar(Matrix *mat, float num);
bool substrScalar(Matrix *mat, float num);
bool multiScalar(Matrix *mat, float num);
float minimalValue(const Matrix *mat);
float maximalValue(const Matrix *mat);
bool addMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat);
bool substrMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat);
bool copyMatrix(const Matrix *mat1, Matrix *mat2);
bool multiMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat);
bool printMatrix(const Matrix *mat);
