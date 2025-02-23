#include <stdio.h>
#include <math.h>
// ax^2 + bx + c = 0//

int quadraticEquation(float a1, float b1, float c1, float *px1, float *px2);

void main()
{
    float a, b, c, x1, x2;
    printf("Въведете a = ");
    scanf("%f", &a);
    printf("Въведете b = ");
    scanf("%f", &b);
    printf("Въведете c = ");
    scanf("%f", &c);
    
    int result = quadraticEquation(a, b, c, &x1, &x2);

    switch (result)
    {
    case 0:
        printf("Няма решение\n");
        break;
    
    case 1:
        printf("Всяко x е решение\n");
        break;
    
    case 2:
        printf("x1 = %f, x2 = %f\n", x1, x2);
        break;  
    case 3:
        printf("x = %f\n", x1);
        break;

    default:
        break;
    }
}

int quadraticEquation(float a1, float b1, float c1, float *px1, float *px2)
{
    float D;
    if (a1 == 0) {
        if (b1 == 0) {
            if (c1 == 0) {
                return 1; 
            } else {
                return 0;
            }
        } else {
            *px1 = -c1 / b1; 
            return 3;
        }
    } else {
        D = b1 * b1 - 4 * a1 * c1;
        if (D > 0) {
            *px1 = (-b1 + sqrt(D)) / (2 * a1);
            *px2 = (-b1 - sqrt(D)) / (2 * a1);
            return 2;
        } else if (D == 0) {
            *px1 = -b1 / (2 * a1);
            return 3; 
        } else {
            return 0;
        }
    }
}
