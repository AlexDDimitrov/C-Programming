#include <stdio.h>
#include "mystrings.h"

int stringlen(char *string) {
    int i;
    for (i = 0; string[i]!=0;i++);
    return i;
}