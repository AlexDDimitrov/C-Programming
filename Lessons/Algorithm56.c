#include<stdio.h>
//grades of a class - avr, the people with 6 and the people with 2//
void main()
{	
    int i = 0, n;
    do {
        printf("Enter the number of students = ");
        scanf("%d", &n);
    } while(n < 2);
    int A[n];
    int avr = 0;
    for (i=0; i<n; i++)
    {
        do{
        printf("Enter the grade of student %d = ", i+1);
        scanf("%d", &A[i]);
        } while(A[i] < 2 || A[i] > 6);
    }
    for (i=0; i<n; i++)
    {
        avr = avr + A[i];
    }
    avr = avr/i;
    printf("The average grade is: ");
    printf("%d\n", avr);
    for (i=0; i<n; i++)
    {
        if (A[i] == 6)
        {
            printf("Student %d has grade 6\n", i+1);
        }
    }	
    for (i=0; i<n; i++)
    {
        if (A[i] == 2)
        {
            printf("Student %d has grade 2\n", i+1);
        }
    }
}