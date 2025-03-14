#include <stdio.h>

void main ()
{
    float mass, mass_moon;
    printf ("mass = ");
    scanf("%f", &mass);

    mass_moon= 83*mass/100;
    printf("your mass on the moon is %.2f", mass_moon);
}