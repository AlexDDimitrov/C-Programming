#include<stdio.h>
//odd and even arrays//
#define MAX 10
void main()
{	
    int A[MAX];
    int ODD[MAX], EVEN[MAX];
    int i, n;
    int j = 0, k = 0;
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
    for (i=0; i<n; i++)
    {
        if (A[i] % 2 == 0)
        {
            EVEN[j] = A[i];
            j++;
        }
        else
        {
            ODD[k] = A[i];
            k++;
        }
    }
    printf("\nThe odd array is: ");
    for (i=0; i<k; i++)
    {
        printf("%d, ", ODD[i]);
    }
    printf("\nThe even array is: ");
    for (i=0; i<j; i++)
    {
        printf("%d, ", EVEN[i]);
    }
}
