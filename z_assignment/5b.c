#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int count)

{
    int temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main()
{
    FILE *fp = NULL;
    fp = fopen("numbers.txt", "r");
    int arr[100], count = 0, num;

    if (fp == NULL)
    {
        printf("File does not exist.");
        exit(1);
    }

    while (fscanf(fp, "%d", &num) != EOF)
    {
        arr[count++] = num;
    }

    fclose(fp);

    // sort the array:
    bubbleSort(arr, count);

    // re-write in file.

    fp = fopen("numbers.txt", "w");
    if (fp == NULL)
    {
        printf("File does not exist.");
        exit(1);
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d\n", arr[i]); // note: \n is must.
    }

    fclose(fp);
    printf("File Sorting completed!");
}