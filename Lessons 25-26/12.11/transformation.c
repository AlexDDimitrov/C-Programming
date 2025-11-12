#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transformation.h"

transformation string_to_long(char *input) {
    transformation tmp;
    tmp.result = 0;
    tmp.error[0] = '\0';
    int negative = 0;

    if (input == NULL || *input == '\0') {
        strcpy(tmp.error, "Invalid input string");
        return tmp;
    }

    for (int i = 0; input[i] != 0; i++) {        
        if (input[i] >= '0' && input[i] <= '9' || input[i] == '-' || input[i] == '\0') {
            if (input[i] == '\0') {
                break;
            }
            
            if (input[i] == '-') {
                negative = 1;
            } else {
                tmp.result *= 10;
                tmp.result += input[i] - '0';
            }
        } else {
            strncpy(tmp.error, "Invalid input string", 99);
            tmp.result = 0;
            break;
        }
    }
    if (negative == 1) {
        tmp.result = - tmp.result;
    }

    return tmp;
}
