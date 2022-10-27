# CS205-Project3: A library for Matrix Operations in C
___

### 项目简介：
本项目实现了一个C语言下的矩阵库。该库支持创建矩阵，删除矩阵，复制矩阵，对矩阵加/减/乘一个常数或者另一个矩阵，以及找矩阵最大值和最小值等操作。该库实现了良好的内存安全性，防止误使用导致内存泄漏。
另外，该项目附带了一个程序用于测试，可以方便地使用该库的各个功能。
![a](./b.png)

###Part 1: Analysis
需求：实现矩阵库，让用户可以方便且安全地应用。
应当含有的函数有:
```
create a matrix, createMatrix().
delete a matrix, deleteMatrix().
copy a matrix (copy the data from a matrix to another), copyMatrix().
add two matrices, addMatrix().
subtraction of two matrices, subtractMatrix()
add a scalar to a matrix.
subtract a scalar from a matrix.
multiply a matrix with a scalar.
multiply two matrices.
find the minimal and maximal values of a matrix.
some other functions needed
```

###Part 2: Code
关键部分代码：
1. 存储矩阵
```
typedef struct Matrix 
{
	size_t rows, columns;
	float *datas;
} Matrix;
```
为了防止局部变量导致内存泄漏，对两个矩阵的运算都要求用户输入第三个大小合适的矩阵进行存储。这些操作的返回类型为$bool$，返回$true$表示成功赋值新的矩阵，返回$false$表示出现异常（如参数为$NULL$，或者大小不匹配等。
举例（矩阵相乘）：
```
bool multiMatrix(const Matrix *mat1, const Matrix *mat2, Matrix *ansMat)
{
    /*make the matrix ansMat to mat1 * mat2
    /requires corresponding size
    You shouldn't make ansMat equal to mat1 or mat2 */
    if (mat1 == NULL || mat2 == NULL || ansMat == NULL) return 0;
	if (mat1->columns != mat2->rows) return 0;
    if (mat1->rows != ansMat->rows || mat2->columns != ansMat->columns) return 0;
    if (mat1 == ansMat || mat2 == ansMat) return 0;
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
```
删除操作要求输入指针的地址，否则可能会导致野指针的存在。
```
bool deleteMatrix(Matrix **mat)
{
    /*delete the matrix and free the memory
    return 1 if delete successfully*/
	if (*mat == NULL) return 0;
	if ((*mat)->datas != NULL) free((*mat)->datas);
	free(*mat);
	*mat = NULL;
    return 1;
}
```

### Part 3: Result& Verification
#### Case 1:
Create a empty matrix
![a](./c.png)
Output it
![a](./d.png)
#### Case 2:
Assign the matrix to:
$$
 \left[
 \begin{matrix}
   1 & 2 & 3 \\
   4 & 3 & 2 \\
   1.5 & 0.5 & 1
  \end{matrix}
  \right] \tag{3}
$$
![a](./e.png)
Output it
![a](./f.png)
#### Case 3:
create another $3*3$ matrix and copy the first one to this one
![a](./g.png)
![a](./h.png)
![a](./i.png)
#### Case 4:
add scalar $0.5$ to the elements of matrix 2
![a](./j.png)
![a](./k.png)
#### Case 5:
substract elements of matrix 1 by $0.5$
![a](./l.png)
![a](./m.png)
#### Case 6:
multiply matrix 1 by $1.5$
![a](./n.png)
![a](./o.png)
#### Case 7:
create matrix 3 of $3 * 3$, make matrix 3 to matrix 1 + matrix 2
![a](./p.png)
![a](./q.png)
#### Case 8:
create matrix 4 of $3 * 3$, make matrix 4 to matrix 1 - matrix 2
![a](./r.png)
![a](./s.png)
#### Case 9:
create matrix 5 of $3 * 3$, make matrix 5 to matrix 3 * matrix 4
![a](./t.png)
![a](./u.png)
#### Case 10:
find the minimum value of matrix 5
![a](./v.png)
#### Case 11:
find the maximum value of matrix 5
![a](./w.png)
### Below are exception handling
#### Case 12:
delete a matrix more than one time
![a](./x.png)
#### Case 13:
make the operation matrix and storage matrix same
(it won't be successful because the operation matrices SHOULDN'T be modified, it is const matrices)
![a](./y.png)
#### Case 14:
if the size of answer matrix has something wrong
we create matrix 1(deleted) a $3*4$ matrix
![a](./z.png)
![a](./aa.png)
it remains the same
![a](./ab.png)
