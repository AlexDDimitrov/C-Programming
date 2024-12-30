#include <stdio.h>

float o_to_c(float un);

void main()
{
    float u, g;
    printf("u = ");
    scanf("%f", &u);

    g = o_to_c(u);
    printf("The glasses are %.2f\n", g);
}

float o_to_c(float un)
{
    return un / 8;
}