# include <stdio.h>
# include <conio.h>
void main ()
{
    char a, s, i;
    printf("Enter 10 characters:");
    s = 'z';
    for (i=0; i<10; i++)
    {
    a = getche();
    if (a < s)
    {
        s = a;
    }
    
    }
    printf("The character that is infront in alphabetical order is %c\n", a);
    
}