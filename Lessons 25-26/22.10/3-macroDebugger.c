#include <stdio.h>

#define DEBUG(X) { \
    printf("DEBUGGER:\n"); \
    printf("Filename: %s\n", __FILE__); \
    printf("Time: %s\n", __TIME__); \
    printf("Line: %d\n", __LINE__); \
    printf("The value of %s is %d\n", #X, X); \
    printf("\n"); \
}

int main() {
    int a = 5;

    DEBUG(a);

    return 0;
}