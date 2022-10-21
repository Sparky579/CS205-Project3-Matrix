#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Matrix Matrix;
bool sameSize(const Matrix *mat1, const Matrix *mat2);
float * pos(const Matrix *mat, size_t r, size_t c);
Matrix * createMatrix(size_t rows, size_t columns);
void deleteMatrix(Matrix **mat);
bool addScalar(Matrix *mat, size_t r, size_t c, int num);
bool substrScalar(Matrix *mat, size_t r, size_t c, int num);
bool multiScalar(Matrix *mat, int num);
float minimalValue(const Matrix *mat);
float maximalValue(const Matrix *mat);
bool addMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat);
bool subtractMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat);
bool copyMatrix(const Matrix *mat1, Matrix *mat2);
bool multiMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat);
void printMatrix(const Matrix *mat);
