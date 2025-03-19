#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int k, n, i;
    srand(time(0)); 
    k = rand() % 100 + 1;

    for (i = 0; i < 10; i++)
    {

        printf("\nEnter you guess: ");
        scanf("%d", &n);

        if (n == k)
        {
            printf("You are right!\nThe magic number is %d!\n", k);
            break;
        }
        else
        {
            printf("Try again!");
            if (n < k)
                printf("\nThe number is greater than %d.", n);
            else
                printf("\nThe number is smaller than %d.", n);
            printf("\nYou have %d tries left.\n", 9 - i);
        }
    }

    if (i == 10)
        {
            printf("\nYou have lost!");
            printf("\nThe magic number was %d", k);
        }
    return 0;
}