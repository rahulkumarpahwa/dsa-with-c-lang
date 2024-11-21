#include <stdio.h>
#include <stdlib.h>

void main()
{
    int arows, acolumns, brows, bcolumns, a[100][100], b[100][100], c[100][100],sum = 0;

    printf("Enter the no. of rows in A matrix:\n");
    scanf("%d", &arows);
    printf("Enter the no. of columns in A matrix:\n");
    scanf("%d", &acolumns);
    printf("Enter the no. of rows in B matrix:\n");
    scanf("%d", &brows);
    printf("Enter the no. of columns in B matrix:\n");
    scanf("%d", &bcolumns);

    printf("Enter value in matrix A: \n");
    for (int i = 0; i < arows; i++)
    {
        for (int j = 0; j < acolumns; j++)
        {
            printf("Element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter value in matrix B: \n");
    for (int i = 0; i < brows; i++)
    {
        for (int j = 0; j < bcolumns; j++)
        {
            printf("Element b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    // addition : (both the size of the arrays must be same.)
    for (int i = 0; i < arows; i++)
    {
        for (int j = 0; j < acolumns; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Sum: \n");
    for (int i = 0; i < brows; i++)
    {
        for (int j = 0; j < bcolumns; j++)
        {
            printf(" %d ",c[i][j]);
        }
        printf("\n");
    }

    // subtraction : size must be same.
    for (int i = 0; i < arows; i++)
    {
        for (int j = 0; j < acolumns; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Subtraction: \n");
    for (int i = 0; i < brows; i++)
    {
        for (int j = 0; j < bcolumns; j++)
        {
            printf(" %d ",c[i][j]);
        }
        printf("\n");
    }

    // multiplication (acolumns must be equal to brows):
  
    for (int i = 0; i < arows; i++)
    {
        for (int j = 0; j < bcolumns; j++)
        {
            for (int k = 0; k < acolumns ; k++) // here k can be either less than a's column or b's row
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }

    printf("multiplication: \n");
    for (int i = 0; i < brows; i++)
    {
        for (int j = 0; j < bcolumns; j++)
        {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
}