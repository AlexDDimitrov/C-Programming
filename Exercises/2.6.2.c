# include <stdio.h>
void main (void)
{
    int i, k;
    printf("i = ");
    scanf("%d", &i);
    for(k=i; k>0; k--) printf("%d\n", k);
    printf("\a");
}