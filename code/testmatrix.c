#include "matrix.c"
Matrix* matrix[11];
int main()
{
    printf("It is a program for test\n");
    for (int i = 0; i < 11; i++) matrix[i] = 0;
    while (1) {
        printf("\n\n\n");
        printf("1: create a matrix 2: assign a matrix\n");
        printf("3: delete a matrix 4: add a scalar to one position 5: substract a scalar to one position\n");
        printf("6: add a scalar to whole matrix 7: substract a scalar to whole matrix 8: multiply a scalar to matrix\n");
        printf("9: minimum of a matrix 10: maximum of a matrix\n");
        printf("11: copy a matrix 12: add two matrices 13: substract two matrices\n");
        printf("14: multiply two matrices 15: print out a matrix\n");
        printf("16: exit the program\n");
        int mode = 0, r, c;
        float num;
        bool ret;
        scanf("%d",&mode);
        int id1, id2, id3;
        switch (mode)
        {
        case 1:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            if (matrix[id1] != NULL) {
                printf("Are you sure you want to cover this matrix?\n");
                printf("If sure, type 1: ");
                scanf("%d",&id2);
                if (id2 != 1) break;
                else deleteMatrix(&matrix[id1]);
            } 
            printf("Input rows: ");
            scanf("%d",&r);
            printf("Input columns: ");
            scanf("%d",&c);
            matrix[id1] = createMatrix(r, c);
            if (matrix[id1] != NULL) {
                printf("Create successfully!\n");
            }
            else printf("Failed to create!\n");
            break;
        case 2:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            if (matrix[id1] == NULL) {
                printf("It is NULL!\n");
            }
            else {
                printf("Input %d numbers to assign\n", matrix[id1]->columns * matrix[id1]->rows);
                for (int r = 0; r < matrix[id1]->rows; r++) {
                    for (int c = 0; c < matrix[id1]->columns; c++) {
                        float tmp;
                        scanf("%f",&tmp);
                        setPosition(matrix[id1], r, c, tmp);
                    }
                }
                printf("Assigned successfully!\n");
            }
            break;
        case 3:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            ret = deleteMatrix(&matrix[id1]);
            if (ret == 0) printf("Failed to delete!\n");
            else printf("Successfully deleted!\n");
            break;
        case 4:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            printf("Input rows: ");
            scanf("%d",&r);
            printf("Input columns: ");
            scanf("%d",&c);
            printf("Input the num: ");
            scanf("%f",&num);
            ret = addPosition(matrix[id1], r, c, num);
            if (ret == 0) printf("Failed to add!\n");
            else printf("Successfully added!\n");
            break;
        case 5:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            printf("Input rows: ");
            scanf("%d",&r);
            printf("Input columns: ");
            scanf("%d",&c);
            printf("Input the num: ");
            scanf("%f",&num);
            ret = substrPosition(matrix[id1], r, c, num);
            if (ret == 0) printf("Failed to substract!\n");
            else printf("Successfully substracted!\n");
            break;
        case 6:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            printf("Input the num: ");
            scanf("%f",&num);
            ret = addScalar(matrix[id1], num);
            if (ret == 0) printf("Failed to add!\n");
            else printf("Successfully added!\n");
            break;
        case 7:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            printf("Input the num: ");
            scanf("%f",&num);
            ret = substrScalar(matrix[id1], num);
            if (ret == 0) printf("Failed to substract!\n");
            else printf("Successfully substracted!\n");
            break;
        case 8:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            printf("Input the num: ");
            scanf("%f",&num);
            ret = multiScalar(matrix[id1], num);
            if (ret == 0) printf("Failed to multiply!\n");
            else printf("Successfully multiplied!\n");
            break;
        case 9:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            if (matrix[id1] == NULL) printf("Failed to find!\n");
            else printf("%f\n",minimalValue(matrix[id1]));
            break;
        case 10:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            if (matrix[id1] == NULL) printf("Failed to find!\n");
            else printf("%f\n",maximalValue(matrix[id1]));
            break;
        case 11:
            printf("Input the matrix id 1: ");
            scanf("%d",&id1);
            printf("Input the matrix id 2: ");
            scanf("%d",&id2);
            ret = copyMatrix(matrix[id1], matrix[id2]);
            if (ret == 0) printf("Failed to copy!\n");
            else printf("Successfully copied!\n");
            break;
        case 12:
            printf("Input the matrix id 1: ");
            scanf("%d",&id1);
            printf("Input the matrix id 2: ");
            scanf("%d",&id2);
            printf("Input what matrix to store the answer: ");
            scanf("%d",&id3);
            ret = addMatrix(matrix[id1], matrix[id2], matrix[id3]);
            if (ret == 0) printf("Failed to add!\n");
            else printf("Successfully added!\n");
            break;  
        case 13:
            printf("Input the matrix id 1: ");
            scanf("%d",&id1);
            printf("Input the matrix id 2: ");
            scanf("%d",&id2);
            printf("Input what matrix to store the answer: ");
            scanf("%d",&id3);
            ret = substrMatrix(matrix[id1], matrix[id2], matrix[id3]);
            if (ret == 0) printf("Failed to substract!\n");
            else printf("Successfully substracted!\n");
            break;
        case 14:
            printf("Input the matrix id 1: ");
            scanf("%d",&id1);
            printf("Input the matrix id 2: ");
            scanf("%d",&id2);
            printf("Input what matrix to store the answer: ");
            scanf("%d",&id3);
            ret = multiMatrix(matrix[id1], matrix[id2], matrix[id3]);
            if (ret == 0) printf("Failed to multiply!\n");
            else printf("Successfully multiplied!\n");
            break;
        case 15:
            printf("Input the matrix id: ");
            scanf("%d",&id1);
            ret = printMatrix(matrix[id1]);
            if (ret == 0) printf("Failed to print!\n");
            else printf("Successfully printed!\n");
            break;
        case 16:
            return 0;
        default:
            break;
        }
    }
}
