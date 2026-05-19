#include<stdio.h>
//symetric array//
#define MAX 10
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
    
    
        for (i=0; i<n/2; i++)
        {
            if (A[i] != A[n-1-i])
            {
                printf("The array is not symetric\n");
                break;
            }
        }
        if (i == n/2)
        {
            printf("The array is symetric\n");
        }
}