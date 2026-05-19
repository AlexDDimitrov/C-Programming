#include <stdio.h>
//дали дадена цифра се срещав записа на дадена цифре//
int found(int digit, int number);
void main(void)
{
    int digit, number;
    int p;
    printf("\nEmter digit: ");
    scanf("%d", &digit);
    printf("\nEmter number: ");
    scanf("%d", &number);
    p=found(digit, number);
    if (p==1) printf("\nYes");
    else printf("\nNo");
}

int found(int digit, int number)
{
    while (number>0)
    {
        if (number%10==digit) return 1;
        number=number/10;
    }
    return 0;
}