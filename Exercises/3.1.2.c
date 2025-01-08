# include <stdio.h>
# include <conio.h>
int main (void)
{
    char a;
    
    for (a='A'; a<='Z'; a++);
    {
        printf("%c ", a);
    }
    printf("\n");
    for (a='a'; a<='z'; a++);
    {
        printf("%c ", a);
    }
    
    return 0;
    
}