#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAY_SIZE 
#define ARRAY_SIZE 3
#endif


int powerOfTwo(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= 2;
    }
    return result;
}

int main() {
    #if ARRAY_SIZE > 0 && ARRAY_SIZE < 11
        int arr[ARRAY_SIZE] = {0};
        for (int i = 0; i < ARRAY_SIZE; i++) {
            arr[i] = powerOfTwo(i); 
        }
        
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d\n", arr[i]);
        }
    #else
        printf("No valid array size defined. Please define ARRAY_SIZE between 1 and 10.\n");
    #endif
    return 0;
}