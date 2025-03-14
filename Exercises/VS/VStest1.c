#include <stdio.h>
int a = 18;
int main()
{
    int a = 7;
    {
        int a = 3;
        a++;
        printf("%d", a);
    }
    printf("%d", a);
    a++;
    printf("%d", a);
}
