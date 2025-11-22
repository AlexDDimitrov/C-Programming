#include "safeint.h"
#include <limits.h>

struct SafeInt safe;

int safe_add(int a, int b) {
    safe.errorflag = 0;

    if ((b > 0 && a > INT_MAX - b) ||
        (b < 0 && a < INT_MIN - b)) 
    {
        safe.errorflag = 1;
        safe.value = 0;
        return 0;
    }

    safe.value = a + b;
    return safe.value;
}

int safe_subtract(int a, int b) {
    safe.errorflag = 0;

    if ((b > 0 && a < INT_MIN + b) ||
        (b < 0 && a > INT_MAX + b))
    {
        safe.errorflag = 1;
        safe.value = 0;
        return 0;
    }

    safe.value = a - b;
    return safe.value;
}

int safe_multiply(int a, int b) {
    safe.errorflag = 0;

    long long r = (long long)a * (long long)b;
    if (r > INT_MAX || r < INT_MIN) {
        safe.errorflag = 1;
        safe.value = 0;
        return 0;
    }

    safe.value = (int)r;
    return safe.value;
}

int safe_divide(int a, int b) {
    safe.errorflag = 0;

    if (b == 0) {
        safe.errorflag = 1;
        safe.value = 0;
        return 0;
    }

    if (a == INT_MIN && b == -1) {
        safe.errorflag = 1;
        safe.value = 0;
        return 0;
    }

    safe.value = a / b;
    return safe.value;
}

int safeTurnStrToInt(const char *s) {
    safe.errorflag = 0;
    safe.value = 0;

    int sign = 1;

    if (*s == '+') s++;
    else if (*s == '-') { sign = -1; s++; }

    while (*s) {
        if (*s < '0' || *s > '9') {
            safe.errorflag = 1;
            return 0;
        }

        int old = safe.value;
        if (safe_multiply(safe.value, 10), safe.errorflag) return 0;

        if (safe_add(old * 10, *s - '0'), safe.errorflag) return 0;

        safe.value = old * 10 + (*s - '0');
        s++;
    }

    safe.value *= sign;

    return safe.value;
}
