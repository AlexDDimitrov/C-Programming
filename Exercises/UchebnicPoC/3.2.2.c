#include <stdio.h>
#include <conio.h>

int main(void)
{
    char ch;
    int s1, s2, s;
    float r;

    printf("Circle, Triangle or Square? (C/T/S): ");
    ch = getche();
    printf("\n");

    if (ch == 'C' || ch == 'c')
    {
        printf("Enter the radius of the circle: ");
        scanf("%f", &r);
        printf("The area of the circle is: %.2f\n", 3.14159 * r * r);
    }
    else if (ch == 'T' || ch == 't')
    {
        printf("Enter the base and height of the triangle: ");
        scanf("%d %d", &s1, &s2);
        printf("The area of the triangle is: %.2f\n", 0.5 * s1 * s2);
    }
    else if (ch == 'S' || ch == 's')
    {
        printf("Enter the side of the square: ");
        scanf("%d", &s1);
        s = s1 * s1;
        printf("The area of the square is: %.2f\n", (float)s);
    }
    else
    {
        printf("Invalid input\n");
    }

    return 0;
}