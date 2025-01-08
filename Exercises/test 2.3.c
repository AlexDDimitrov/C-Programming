#include <stdio.h>

int main()
{
    int a, c, r, w;

    r = 0;
    w = 0;

    for(c=1; c < 11; c++) 
    {
        printf("What is %d + %d? ", c, c);
        scanf("%d", &a);

        if(a == c+c) 
        {
            printf("Right! ");
            r++;
        }
        else 
        {
            printf("Sorry, you're wrong. ");
            printf("The answer is %d. ", c+c);
            w++;
        }
    }
    printf("You got %d right and %d wrong.", r, w);

    return 0;
}
