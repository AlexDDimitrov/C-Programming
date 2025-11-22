#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "safeint.h"
#include "utill.h"
int main(int argc, char **argv) {
    if (argc < 3) {
        print_missing_arg_error();
        return 1;
    }

    int a = safeTurnStrToInt(argv[1]);
    if (safe.errorflag) {
        print_arg_error();
        return 1;
    }

    int b = safeTurnStrToInt(argv[2]);
    if (b == 0) {
        print_div0_error();
        return 1;
    }
    if (safe.errorflag) {
        print_arg_error();
        return 1;
    }

    safe_divide(a, b);

    if (safe.errorflag) {
        print_op_error();
        return 1;
    }
 
    printf("Result: %d\n", safe.value);
    return 0;
} 