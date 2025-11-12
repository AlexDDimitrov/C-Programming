#include <stdio.h>

int main() {
    int a = 12;
    int b = 18;

    for (int i = 2; ; i++) {
        if (i % a == 0 && i % b == 0) {
            printf("%d\n", i);
            break;
        }
    }  
}