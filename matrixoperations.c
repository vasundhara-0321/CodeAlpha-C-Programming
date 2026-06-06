#include <stdio.h>

void addMatrix(int r, int c, int A[r][c], int B[r][c]);
void multiplyMatrix(int r1, int c1, int A[r1][c1], int r2, int c2, int B[r2][c2]);
void transposeMatrix(int r, int c, int A[r][c]);

int main()
{
    int r, c, i, j;
    int choice;

    printf("Enter number of rows: ");
    scanf("%d", &r);

    printf("Enter number of columns: ");
    scanf("%d", &c);

    int A[r][c], B[r][c];

    printf("\nEnter elements of Matrix A:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    do
    {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose (A)\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addMatrix(r, c, A, B);
                break;

            case 2:
                multiplyMatrix(r, c, A, r, c, B);
                break;

            case 3:
                transposeMatrix(r, c, A);
                break;

            case 4:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}

void addMatrix(int r, int c, int A[r][c], int B[r][c])
{
    int i, j;

    printf("\nAddition Result:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int r1, int c1, int A[r1][c1], int r2, int c2, int B[r2][c2])
{
    int i, j, k;
    int result[r1][c2];

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMultiplication Result:\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int r, int c, int A[r][c])
{
    int i, j;

    printf("\nTranspose of Matrix A:\n");

    for(j = 0; j < c; j++)
    {
        for(i = 0; i < r; i++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}