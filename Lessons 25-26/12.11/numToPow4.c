#include <stdio.h>
#include <math.h>

long power(long num, long power) {
    long result = pow(num, power);
    return result;  
}

int main() {
    long result = power(2, 4);
    printf("2 to the power of 4 is: %ld\n", result);
    return 0;
}