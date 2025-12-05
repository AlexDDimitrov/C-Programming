#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main(int argc, char *argv[])
{
    int num1 = atoi(argv[1]);

    int result = sum(num1);

    printf("Result: %d\n", result);
    
    return 0;
}
