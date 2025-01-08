#include <stdio.h>

void main()
{
   int r, l=0, w=0, t=0, i;

   printf ("Number of rooms: ");
   scanf("%d", &r);

    for(i=r; i>0; i--)
    {
        printf("Lenght: ");
        scanf("%d", &l);

        printf("Width: ");
        scanf("%d", &w);
        t=t+l*w;

    }
    printf("\nTotal area in square meters: %d", t);

}