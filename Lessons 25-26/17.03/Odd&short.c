#include <stdio.h>
union Number{
    long odd;
    short even;
};

int main(void) {
    union Number arr[10];

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {  
            arr[i].even = i;
        } else {
            arr[i].odd = i;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            printf("Index %d: odd = %ld\n", i, arr[i].odd);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            printf("Index %d: even = %hd\n", i, arr[i].even);
        }
    }
}