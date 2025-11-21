#ifndef SAFEINT_H
#define SAFEINT_H

struct SafeInt {
    int value;
    int errorflag;
};

struct SafeInt safe;

int safe_add(int a, int b);
int safe_subtract(int a, int b);
int safe_multiply(int a, int b);
int safe_divide(int a, int b);
int safeTurnStrToInt();

#endif