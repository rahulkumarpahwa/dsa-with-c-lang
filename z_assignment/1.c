// i. Write Programs to demonstrate the concept of recursion
// • Factorial
// • Print n Number of Fibonacci series, where n is positive integer from user
// input

#include <stdio.h>
#include <stdlib.h>

// factorial
int fact(int val)
{
    int f;
    if (val == 1 || val == 0 || val < 0)
    {
        return 1;
    }
    else
    {
        f = val * fact(val - 1);
    }
    return f;
}

//fibonacci series 


void main()
{
    // factorial
    int a = -3;
    printf("The factorial of %d is : %d", a, fact(a));
}