#include <stdio.h>
//ax+b=0//
void main() {
    float a, b, x;


    printf("a= ");
    scanf("%f", &a);
    printf("b= ");
    scanf("%f", &b);

    if (a == 0) {
        if (b == 0) {
            printf("Every answer is right\n");
        } else {
            printf("There is no answer\n");
        }
    } else {
        
        x = -b / a;
        printf("The answer is x = %f\n", x);
    }


}
