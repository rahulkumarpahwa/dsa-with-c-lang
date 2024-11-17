// i. Write Programs to demonstrate the concept of recursion
// 1. Factorial
// 2. Print n Number of Fibonacci series, where n is positive integer from user
// input

#include <stdio.h>
#include <stdlib.h>

// factorial
int fact(int val)
{
    int f;
    if (val == 1 || val == 0)
    {
        return 1;
    }
    else if (val < 0)
    {
        printf("Factorial does not exist. ");
        return 0;
    }
    else
    {
        f = val * fact(val - 1);
    }
    return f;
}

// fibonacci series
int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 2) + fibonacci(n - 1);
    }
}

void main()
{
    // factorial
    int a = -3, terms;
    printf("The factorial of %d is : %d", a, fact(a));
    printf("\n \n");
    printf("Enter the no. of terms: \n");
    scanf("%d", &terms);
    printf("The fibonacci series upto terms %d is : ", terms);
    for (int i = 0; i < terms; i++)
    {
        printf("%d ", fibonacci(i));
    }
}