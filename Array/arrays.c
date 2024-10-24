#include<stdio.h>
#include<stdlib.h>

struct myArray {
    int usedSize;
    int capacity;
    int * arr;
}; 

void arrayTraversal(struct myArray* a){
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d\n", a->arr[i]);
    }
}


void main()
{ 
    struct myArray * a = (struct myArray *) malloc(sizeof(struct myArray));
    a->usedSize = 10;
    a->capacity = 100;
    a->arr = (int *)malloc(sizeof(int) * a->capacity);

    printf("Enter the values in array\n");
    for(int i = 0; i<a->usedSize; i++){
        scanf("%d", &a->arr[i]);
    }

    arrayTraversal(a);

}