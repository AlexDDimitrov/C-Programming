#include "safeint.h"
#include <limits.h>

int safe_add(int a, int b) {
    safe.errorflag = 0;
    if (((b > 0) && (a > INT_MAX - b)) || ((b < 0) && (a < INT_MIN - b))) {
        safe.errorflag = 1;
    }

    safe.value = a + b;
    return safe.value;
}


int safe_subtract(int a, int b) {
    int result;
    safe.errorflag = 0;
    if (b > 0 && a < INT_MIN + b) {
        safe.errorflag = 1;
        safe.value = 0;
        return 0;
    }
    if (b < 0 && a > INT_MAX + b) {
        safe.errorflag = 1;
        safe.value = 0;
        return 0;
    }
    result = a - b;
    return result;
}

int safe_multiply(int a, int b) {
    int result;
    result = a * b;
    return result;
}

int safe_divide(int a, int b) {
    int result;
    result = a / b;
    return result;
}