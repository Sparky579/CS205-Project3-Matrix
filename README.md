# CS205-Project3: A library for Matrix Operations in C
___

### 项目简介：
本项目实现了一个C语言下的矩阵库。该库支持创建矩阵，删除矩阵，复制矩阵，对矩阵加/减/乘一个常数或者另一个矩阵，以及找矩阵最大值和最小值等操作。该库实现了良好的内存安全性，防止误使用导致内存泄漏。
另外，该项目附带了一个程序用于测试，可以方便地使用该库的各个功能。
![a](./images/b.png)

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
![a](./images/c.png)
Output it
![a](./images/d.png)
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
![a](./images/e.png)
Output it
![a](./images/f.png)
#### Case 3:
create another $3*3$ matrix and copy the first one to this one
![a](./images/g.png)
![a](./images/h.png)
![a](./images/i.png)
#### Case 4:
add scalar $0.5$ to the elements of matrix 2
![a](./images/j.png)
![a](./images/k.png)
#### Case 5:
substract elements of matrix 1 by $0.5$
![a](./images/l.png)
![a](./images/m.png)
#### Case 6:
multiply matrix 1 by $1.5$
![a](./images/n.png)
![a](./images/o.png)
#### Case 7:
create matrix 3 of $3 * 3$, make matrix 3 to matrix 1 + matrix 2
![a](./images/p.png)
![a](./images/q.png)
#### Case 8:
create matrix 4 of $3 * 3$, make matrix 4 to matrix 1 - matrix 2
![a](./images/r.png)
![a](./images/s.png)
#### Case 9:
create matrix 5 of $3 * 3$, make matrix 5 to matrix 3 * matrix 4
![a](./images/t.png)
![a](./images/u.png)
#### Case 10:
find the minimum value of matrix 5
![a](./images/v.png)
#### Case 11:
find the maximum value of matrix 5
![a](./images/w.png)
### Below are exception handling
#### Case 12:
delete a matrix more than one time
![a](./images/x.png)
#### Case 13:
make the operation matrix and storage matrix same
(it won't be successful because the operation matrices SHOULDN'T be modified, it is const matrices)
![a](./images/y.png)
#### Case 14:
if the size of answer matrix has something wrong
we create matrix 1(deleted) a $3*4$ matrix
![a](./images/z.png)
![a](./images/aa.png)
it remains the same
![a](./images/ab.png)

### Part 4: Difficulties & Solutions

#### 如何安全高效地存储矩阵？
在学会指针之后，我认识到像前两次Project那样在结构体中直接存储数组是十分低效且浪费内存的。所以，这次的Project作为一个应当实用的库，采用了结构体中只存储一个$float$指针用于表示整个矩阵，再存储$rows$和$columns$变量分别表示矩阵的行和列信息。在使用矩阵中，只将一个结构体的指针传入，避免每次函数调用都赋值一遍整个结构体。当然，带有指针的结构体需要考虑内存安全的问题，库中不能不销毁局部指针，用户在局部使用完后也必须要记得使用$deleteMatrix$。

#### 如何用一个指针模拟整个二维数组？
将二维数组展开变成$rows * columns$个$float$变量，矩阵的$r$行$c$列通过计算可得就是第$r * columns + c$个变量。函数内$pos$方法就是基于此，$pos(mat, r, c)$在不出现异常的情况下返回$datas + (r * columns + c)$的地址。

#### 如何实现安全的删除操作
一开始时，该库使用的删除函数如下：
```
bool deleteMatrix(Matrix *mat)
{   
    if (mat == NULL) return 0;
	//delete a matrix
	//this version requires to set mat=NULL after using
	if (mat == NULL) return;
	if (mat->datas != NULL) free(mat->datas);
	free(mat);
    mat == NULL //*
    return 1;
}
```
但是，$*$的一行被发现实际上是无用的，对一个矩阵调用该方法时会导致它指向的内容被释放，也就是成为了野指针。出现的问题就是再次误调用该指针会出现错误。原因是传入的$mat$是原$mat$的一个复制，原$mat$指针并未因为打$*$的一行而被置为$NULL$。所以将传入的类型改为矩阵指针的指针。想要删除一个矩阵指针的时候传入该指针的地址。即：```deleteMatrix(&mat)```
