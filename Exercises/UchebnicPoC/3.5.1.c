#include <stdio.h>
#include <conio.h>

int main(void)
{
    float g;

    printf("Gallons\n");
    scanf("%f", &g);

    do {
        printf("Liters: %f\n", g * 3.785);

        printf("Enter gallons (0 to end):" );
        scanf("%f", &g);
        
    } while (g != 0);

    return 0;
}