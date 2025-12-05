#ifndef QUADRATICROOTS_H
#define QUADRATICROOTS_H

typedef struct {
    long double x1;
    long double x2;
    int norealroots;
} QuadraticRootResult;

QuadraticRootResult findRoots(long double a, long double b, long double c);

#endif