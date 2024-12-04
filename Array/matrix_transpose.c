#include <stdio.h>
#include <stdlib.h>

void main()
{
    int r, c, arr[100][100];

    printf("Enter the no. of rows\n");
    scanf("%d", &r);

    printf("Enter the no. of columns\n");
    scanf("%d", &c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("enter the element a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    // matrix transpose:
    int temp;
    for (int i = 0; i < r; i++)
    {
        for (int j = i+1; j < c; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}