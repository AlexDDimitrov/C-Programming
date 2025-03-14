#include<stdio.h>
//flipped array//
#define MAX 10
void flip(int A[], int n);
void main()
{	
    int A[MAX];
    int i, n;
    do {
        printf("Enter the number of elements (max 10) = ");
        scanf("%d", &n);
    } while(n < 1 || n > 10);
    for (i=0; i<n; i++)
    {
        printf("Enter element %d = ", i+1);
        scanf("%d", &A[i]);
    }
    printf("The original array is: ");
    for (i=0; i<n; i++)
    {
        printf("%d, ", A[i]);
    }
    flip(A, n);
}
void flip(int A[], int n)
{
    int i;
    for (i=0; i<n/2; i++)
    {
        int B = A[i];
        A[i] = A[n-1-i];
        A[n-1-i] = B;
    }
    printf("\nThe flipped array is: ");
    for (i=0; i<n; i++)
    {
        printf("%d, ", A[i]);
    }
}
