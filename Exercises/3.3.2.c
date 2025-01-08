#include <stdio.h>

int main(void)
{
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    for (; i; i--) ;
    printf("\a");
    return 0;
}