#include<stdio.h>
//avr and change of temperature//
void main()
{
    int i;
    float A[10];
    float avr = 0;
    for (i=0; i<10; i++)
    {
        printf("Enter day %d = ", i+1);
        scanf("%f\n", &A[i]);
    }
    for (i=0; i<10; i++)
    {
        avr = avr + A[i];
    }
    avr = avr/10;
    printf("The average is: ");
    printf("%.2f\n", avr);
    for (i=0; i<10; i++)
    {
        A[i] = A[i] - avr;
        printf("The change of temperature of day %d is: ", i+1);
        printf("%.2f\n", A[i]);
    }
}