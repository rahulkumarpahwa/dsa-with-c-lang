// Write Programs for matrix operations
// • Addition
// • Subtraction
// • Multiplication

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int r, c, i = 0, j = 0;
    int a[100][100], b[100][100], d[100][100];

    printf("Enter the no. of rows: ");
    scanf("%d", &r);

    printf("Enter the no. of columns: ");
    scanf("%d", &c);

    printf("Enter the values in first array: ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Element a%d%d:  ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the values in second array: ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Element a%d%d:  ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    // addition:
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            d[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("The sum of two matrices is : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", d[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\n");
    // subtraction:
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            d[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("The subtraction of two matrices is : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", d[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\n");
    // multiplication :

    int k = 0, sum = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            for (k = 0; k < c; k++) // here k can be either less than a's column or b's row
            {
                sum += a[i][k] * b[k][j];
            }
            d[i][j] = sum;
            sum = 0;
        }
    }

    printf("The multiplication of two matrices is : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", d[i][j]);
        }
        printf("\n\n");
    }
}