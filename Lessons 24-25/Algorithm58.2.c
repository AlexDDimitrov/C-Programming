#include<stdio.h>
#define MAX 10
//Bubble sort - optimised//
void main()
{	
    int i, n;
    int j = 0;
    int A[MAX];
    do {
        printf("Enter the number of elements = ");
        scanf("%d", &n);
    } while(n < 1 || n > 10);
    i=n-1;
    for (i=0; i<n; i++){    
        printf("Enter element %d = ", i+1);
        scanf("%d", &A[i]);
    }
    int sort;
    for (i=0; i<n; i++)
    {
        sort = 1;
        for (j=0; j<n-i-1; j++)
        {
            if (A[j] > A[j+1])
            {
                int k;
                k = A[j];
                A[j] = A[j+1];
                A[j+1] = k;
                sort = 0;
            }
        }
        if (sort == 1)
        {
            break;
        }
    }
    printf("The sorted array is: ");
    for (i=0; i<n; i++)
    {
        printf("%d, ", A[i]);
    }
    
}
