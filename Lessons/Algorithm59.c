#include<stdio.h>
#define MAX 10
//Straight sort//
void main()
{	
    int i, n;
    int k;
    int min = 0, mini;
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
    for (i=0; i<n-1; i++)
    {
        min = A[i];
        mini = i;
        for(k = i+1; k<n; k++)
        {
            if (A[k] < min)
            {
                min = A[k];
                mini = k;
            }
        }
        A[mini] = A[i];
        A[i] = min;
    }
    printf("The sorted array is: ");
    for (i=0; i<n; i++)
    {
        printf("%d, ", A[i]);
    }
    
}
