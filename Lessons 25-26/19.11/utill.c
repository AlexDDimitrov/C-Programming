#include <stdio.h>
#include "utill.h"

void print_arg_error() {
    printf("Error: argument is out of int range.\n");
}

void print_op_error() {
    printf("Error: integer overflow/underflow during operation.\n");
}

void print_missing_arg_error() {
    printf("Error: Please provide two integers as arguments.\n");
}

void print_div0_error() {
    printf("Error: division by zero is not allowed.\n");
}