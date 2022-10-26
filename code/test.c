#include"matrix.c"

int main()
{
    printf("It is a program for test\n");
	Matrix *mx = createMatrix(3, 3);
	Matrix *mx2 = createMatrix(3, 3);
    printf("mx[2][2]: ");
	printf("%f\n",*pos(mx, 2, 2));
	addPosition(mx, 2, 2, 100);
	addPosition(mx2, 2, 2, 200);
    addPosition(mx, 1, 1, 10);
    addPosition(mx, 1, 2, 20);
    Matrix *mx3 = createMatrix(3, 3);
	printf("mx[2][2]: %f\n",*pos(mx, 2, 2));
    printf("mx3[2][2]: %f\n",*pos(mx3, 2, 2));
	
	addMatrix(mx, mx2, mx3);
	printf("mx3[2][2]: %f\n",*pos(mx3, 2, 2));
	
    Matrix *mx4 = createMatrix(3, 7);
    printf("matrix mx: \n");
    printMatrix(mx);
    printf("matrix mx2: \n");
    printMatrix(mx2);
    addScalar(mx, 1);
    addScalar(mx2, 2);
    printf("\nmatrix mx:\n");
    printMatrix(mx);
    printf("\nmatrix mx2:\n");
    printMatrix(mx2);
    printf("\n");
    printf("MINIMUM of mx2: %f\n",minimalValue(mx2));
    printf("MAXIMUM of mx2: %f\n",maximalValue(mx2));

    addPosition(mx4, 2, 5, 4);
    addPosition(mx4, 2, 9, 3);
    addPosition(mx4, 1, 5, 2);
    addPosition(mx4, 3, 6, 5);
    addPosition(mx4, 2, 2, 6);
    addPosition(mx4, 1, 4, 1);
    addPosition(mx4, 0, 5, 8);
    Matrix *mx5 = createMatrix(3, 7);

    multiMatrix(mx3, mx4, mx5);
    multiMatrix(mx, mx3, mx4);
    printf("matrix mx: \n");
    printMatrix(mx);
    printf("\nmatrix mx3: \n");
    printMatrix(mx3);
    printf("\nmatrix mx4: \n");
    printMatrix(mx4);
    printf("\nmatrix mx5: \n");
    printMatrix(mx5);

	deleteMatrix(&mx);
    printMatrix(mx);

    Matrix *mx6 = createMatrix(3, 3);
    addScalar(mx6, 1);
    addMatrix(mx6, mx6, mx6);
    printf("MX6: \n");
    printMatrix(mx6);
    addScalar(mx6, -1);
    multiMatrix(mx6, mx6, mx6);
    printf("MX6: \n");
    addPosition(mx6, 1, 1, 99999);
    printMatrix(mx6);
    printf("MX6 max: %f\n",maximalValue(mx6));
    deleteMatrix(&mx2);
    deleteMatrix(&mx3);
    deleteMatrix(&mx4);
    deleteMatrix(&mx5);
    deleteMatrix(&mx6);
    deleteMatrix(&mx2);
    return 0;
//	printf("%d\n",sizeof(struct Matrix));	
}
