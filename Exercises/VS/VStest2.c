#include <stdio.h>
void count()
{
    static int b;
    b++;
    printf("%d\n", b);
}

int main()
{
    count();
    count();
    count();
    count();
    count();
    return 0;
}