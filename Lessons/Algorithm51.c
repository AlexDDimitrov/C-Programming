#include<stdio.h>

void rev()
{
    char c = getchar();
    if (c != '.') rev();
    printf("%c", c);
}

void main()
{
    rev();
}