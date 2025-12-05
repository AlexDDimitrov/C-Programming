#include <stdio.h>
#include "quadraticroots.h"
#include <math.h>

QuadraticRootResult findRoots(long double a, long double b, long double c) {
    QuadraticRootResult result;

    if (a == 0) {
        result.norealroots = 1;
        result.x1 = 0;
        result.x2 = 0;
        return result;
    }

    long double D = (b * b) - (4 * a * c);

    if (D < 0) {
        result.norealroots = 1;
        result.x1 = 0;
        result.x2 = 0;
    } else if(D > 0) {
        result.norealroots = 0;
        result.x1 = (-b + sqrtl(D)) / (2 * a);
        result.x2 = (-b - sqrtl(D)) / (2 * a);
    } else {
        result.norealroots = 0;
        result.x1 = -b / (2 * a);
        result.x2 = result.x1;
    }

    return result;    
}