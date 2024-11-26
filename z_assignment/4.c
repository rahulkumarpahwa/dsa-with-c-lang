#include<stdio.h>
#include<stdlib.h>

struct AB{
int a;
float b;
char c;
};

union CD
{
int a;
float b;
char c;
};



void main()
{

struct AB s;
union CD u;

s.a= 22;
s.b = 3.9;
s.c = 'a';

u.a = 24;
u.b = 3.9;
s.c = 'f';

printf("The value of members of the structure are : %d %f %c\n", s.a, s.b, s.c);
printf("The value of members of the union are : %d %f %c\n", u.a, u.b, u.c); // garbage value of int and char, while float remains same.

}