#include<stdio.h>
//Bubble sort//
void main()
{	
    int i, n;
    int j = 0;
    do {
        printf("Enter the number of elements = ");
        scanf("%d", &n);
    } while(n < 1);
    i=n-1;
    int A[i];
    for (i=0; i<n; i++){    
        do{
        printf("Enter element %d = ", i+1);
        scanf("%d", &A[i]);
        } while (A[i] < 1);
    }
    for (i=0; i<n; i++)
    {
        for (j=1; j<n-i; j++)
        {
            if (A[j] > A[j+1])
            {
                int k = A[j];
                A[j] = A[j+1];
                A[j+1] = k;
            }
        }
    }
    printf("The sorted array is: ");
    for (i=0; i<n; i++)
    {
        printf("%d, ", A[i]);
    }
    
}
