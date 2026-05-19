#include<stdio.h>
//avr and change of temperature; max days - 30//
#define MAX 30
void main()
{
    float A [MAX];	
    int i, n;
    do {
        printf("Enter the number of days (max 30) = ");
        scanf("%d", &n);
    } while(i > 1 && i < 30);
    float avr = 0;
    for (i=0; i<n; i++)
    {
        printf("Enter day %d = ", i+1);
        scanf("%f\n", &A[i]);
    }
    for (i=0; i<n; i++)
    {
        avr = avr + A[i];
    }
    avr = avr/i;
    printf("The average is: ");
    printf("%.2f\n", avr);
    for (i=0; i<n; i++)
    {
        A[i] = A[i] - avr;
        printf("The change of temperature of day %d is: ", i+1);
        printf("%.2f\n", A[i]);
    }
}