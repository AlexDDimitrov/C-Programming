#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main(int argc, char *argv[])
{
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int result = MAX(num1, num2);
    printf("Result: %d\n", result);
    
    return 0;
}
