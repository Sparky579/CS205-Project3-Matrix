#pragma once
#include "matfunction.h"
typedef struct Matrix 
{
	size_t rows, columns;
	float *datas;
} Matrix;
const int MatrixSize = sizeof(Matrix);
bool sameSize(const Matrix *mat1, const Matrix *mat2)
{
	return mat1->rows == mat2->rows && mat1->columns == mat2->columns;
}
float * pos(const Matrix *mat, size_t r, size_t c)
{
	if (r >= mat->rows || c >= mat->columns)
		return NULL;
	return mat->datas + (r * mat->columns + c);
}
Matrix * createMatrix(size_t rows, size_t columns)
{
	//create a matrix of r * c whose elements are all 0
	if (rows <= 0 || columns <= 0) return NULL;
	Matrix* mx = (Matrix*) malloc(MatrixSize);
	mx->datas = (float*)malloc(4 * rows * columns);
	memset(mx->datas, 0, 4 * rows * columns);
	mx->rows = rows;
	mx->columns = columns;
	return mx;
}
void deleteMatrix(Matrix **mat)
{
    //delete the matrix and free the memory
	if (*mat == NULL) return;
	if ((*mat)->datas != NULL) free((*mat)->datas);
	free(*mat);
	*mat = NULL;
}
/*void deleteMatrix(Matrix *mat)
{
	//delete a matrix
	//this version requires to set mat=NULL after using
	if (mat == NULL) return;
	if (mat->datas != NULL) free(mat->datas);
	free(mat);
}*/
bool addScalar(Matrix *mat, size_t r, size_t c, int num)
{
	//add a scalar num to mat[l][r]
	if (mat->rows <= r || mat->columns <= c) return 0;
	*pos(mat, r, c) += num;
	return 1;
}
bool substrScalar(Matrix *mat, size_t r, size_t c, int num)
{
	//substract a scalar num to mat[l][r]
	return addScalar(mat, r, c, -num);
}
bool multiScalar(Matrix *mat, int num)
{
    //make matrix mat (num) times
    for (int i = 0; i < mat->columns * mat->rows; i++) {
        *(mat->datas+i) *= num;
    }
    return 1;
}
float minimalValue(const Matrix *mat)
{
    float ans = *(mat->datas);
    for (int r = 0; r < mat->rows; r++){
        for (int c = 0; c < mat->columns; c++) {
            if (ans > (*pos(mat, r, c))) ans = (*pos(mat, r, c));
        }
    }
    return ans;
}
float maximalValue(const Matrix *mat)
{
    float ans = *(mat->datas);
    for (int r = 0; r < mat->rows; r++){
        for (int c = 0; c < mat->columns; c++) {
            if (ans < (*pos(mat, r, c))) ans = (*pos(mat, r, c));
        }
    }
    return ans;
}
bool addMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat)
{
    //make matrix ansMat equals to mat1 + mat2
    //requires same size
	if (!(sameSize(mat1, mat2) && sameSize(mat2, ansMat))) return 0;
	for (int i = 0; i < mat1->rows * mat1->columns; i++) {
		*(ansMat->datas + i) = *(mat1->datas + i) + *(mat2->datas + i);
	}
	return 1;
}
bool subtractMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat)
{
    //make matrix ansMat equals to mat1 + mat2
    //requires same size
	if (!(sameSize(mat1, mat2) && sameSize(mat2, ansMat))) return 0;
	for (int i = 0; i < mat1->rows * mat1->columns; i++) {
		*(ansMat->datas + i) = *(mat1->datas + i) - *(mat2->datas + i);
	}
	return 1;
}
bool copyMatrix(const Matrix *mat1, Matrix *mat2)
{
    //copy the matrix mat1 to mat2
    //requires same size
	if (!sameSize(mat1, mat2)) return 0;
	for (int i = 0; i < mat1->rows * mat1->columns; i++) {
		*(mat2->datas + i) = *(mat1->datas + i);
	}
	return 1;
}
bool multiMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat)
{
    //make the matrix ansMat to mat1 * mat2
    //requires corresponding size
	if (mat1->columns != mat2->rows) return 0;
    if (mat1->rows != ansMat->rows || mat2->columns != ansMat->columns) return 0;
    for (int r = 0; r < ansMat->rows; r++) {
        for (int c = 0; c < ansMat->columns; c++){
            *pos(ansMat, r, c) = 0;
            for (int i = 0; i < mat1->columns; i++) {
                *pos(ansMat, r, c) += (*pos(mat1, r, i)) * (*pos(mat2, i, c));
            }
        }
    } 
    return 1;
}
void printMatrix(const Matrix *mat)
{
    //print out the matrix
    for (int r = 0; r < mat->rows; r++) {
        for (int c = 0; c < mat->columns; c++){
            printf("%.0f ", *pos(mat, r, c));
        }
        printf("\n");
    } 
}
