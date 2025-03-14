#include <stdio.h>

int main(void)
{
    float d, s;
    int n;

    printf("Enter number of drive compilations: ");
    scanf("%d", &n);

    for(; n; n--)
    {
        printf("Enter speed:");
        scanf("%f", &s);
        
        printf("Enter distance:");
        scanf("%f", &d);

        printf("Time: %f\n", d / s);
    }
    return 0;
}