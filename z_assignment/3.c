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

    
}