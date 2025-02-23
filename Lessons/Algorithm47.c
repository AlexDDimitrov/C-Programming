//Уравнение ах+b=0
//Уравнение cх+d=0
// само ако имат по 1 корен да се изведе сборът им
#include<stdio.h>
int uravnenie(float a, float b, float *px);
//не е нужно да се пишат параметрите
void main()
{
    float a, b, x, c, d, y;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    if(uravnenie(a, b, &x)==3 && uravnenie(c, d, &y)) {
        printf("x+y = %f\n", x+y);
    }
    else printf("No");
    
}

int uravnenie(float a, float b, float *px)
{
    if(a==0) {
        if(b==0) return 1;
        else return 2;
    }
    else {
        *px=-b/a;
        return 3;
    }
}