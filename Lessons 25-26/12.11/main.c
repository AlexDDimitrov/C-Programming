#include <stdio.h>
#include "transformation.h"

int main() {
    transformation t1 = string_to_long("-123");
    transformation t2 = string_to_long("12ab23");

    printf("Input: -123  => Result: %ld, Error: %s\n", t1.result, t1.error);
    printf("Input: 12ab23  => Result: %ld, Error: %s\n", t2.result, t2.error);

    return 0;
}
