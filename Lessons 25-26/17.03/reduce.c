#include <stdio.h>

typedef unsigned long long ull;
typedef ull (*funcPtr)(ull, ull);

ull reduce(ull arr[], ull size, funcPtr ptr, ull initial) {
    ull result = initial;
    for (ull i = 0; i < size; i++) {
        result = ptr(result, arr[i]);
    }
    return result;
}

ull add(ull a, ull b) {
    return a + b;
}

int main(void) {
    ull arr[3] = {1, 2, 3};

    ull result = reduce(arr, 3, add, 0);

    printf("Result = %llu\n", result);

    return 0;
}
