#include"matrix.c"

int main()
{
	Matrix *mx = createMatrix(3, 3);
	Matrix *mx2 = createMatrix(3, 3);
	printf("%f\n",*pos(mx, 2, 2));
	addScalar(mx, 2, 2, 100);
	addScalar(mx2, 2, 2, 200);
    addScalar(mx, 1, 1, 10);
    addScalar(mx, 1, 2, 20);
    Matrix *mx3 = createMatrix(3, 3);
	printf("%f\n",*pos(mx, 2, 2));
    printf("%f\n",*pos(mx3, 2, 2));
	
	addMatrix(mx, mx2, mx3);
	printf("%f\n",*pos(mx3, 2, 2));
	
    Matrix *mx4 = createMatrix(3, 7);
    addScalar(mx4, 2, 5, 4);
    addScalar(mx4, 2, 9, 3);
    addScalar(mx4, 1, 5, 2);
    addScalar(mx4, 3, 6, 5);
    addScalar(mx4, 2, 2, 6);
    addScalar(mx4, 1, 4, 1);
    addScalar(mx4, 0, 5, 8);
    Matrix *mx5 = createMatrix(3, 7);

    multiMatrix(mx3, mx4, mx5);
    multiMatrix(mx, mx3, mx4);
    printMatrix(mx);
    printf("\n");
    printMatrix(mx3);
    printf("\n");
    printMatrix(mx4);
    printf("\n");
    printMatrix(mx5);

	deleteMatrix(&mx);
	return 0;
//	printf("%d\n",sizeof(struct Matrix));	
}
