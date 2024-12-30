#include <stdio.h>
void main();
void o_to_c (float glass, float un);

void main ()
{
    float u, g;
    printf ("u = ");
    scanf("%f", &u);

    u= o_to_c (un);
    g=o_to_c (glass);
    printf("The glasses are %.2f", g);
}

void o_to_c (float glass, float un)
{
    glass=un/8;
}