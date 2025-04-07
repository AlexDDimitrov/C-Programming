#include <stdio.h>
#define MAX 10
//Straight insertion sort//
void arr_in(int a[], int n)
{
    int i;
    for (i=0; i<n; i++) {
        printf ("Enter element %d = ", i+1);
        scanf("%d", &a[i]);
    }
}

void arr_sort(int a[], int n)
{
    int i, j, x;
    for (i=1; i<n; i++)
    {
       x = a[i];
       j = i - 1;
       while(j>=0 && a[j] > x)
       {
        a[j+1] = a[j];
        j = j - 1;
       }
       a[j + 1] = x;
    }
}

void arr_out(int a[], int n)
{
    int i;
    printf("Sorted Array: ");
    for (i=0; i<n; i++) {
        printf ("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[MAX], n;
    do {
        printf("Enter number of elements: ");
        scanf("%d", &n);
    } while (n<=0 || n>MAX);

    arr_in(a, n);
    arr_sort(a, n);
    arr_out(a, n);

    return 0;
}