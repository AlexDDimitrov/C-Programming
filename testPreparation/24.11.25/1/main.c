#include <stdio.h>
#include <string.h>
#include "mystrings.h"

#define MAX_LENGTH 255

void main() {
    char osname[MAX_LENGTH];

    #if defined _WIN32
        strncpy(osname, "Windows", MAX_LENGTH);
    #elif defined __APPLE__
        strncpy(osname, "MacOS", MAX_LENGTH);
    #elif defined __linux__
        strncpy(osname, "Linux", MAX_LENGTH);
    #else
        strncpy(osname, "Other", MAX_LENGTH);
    #endif

    PRINT(osname);
    int len = stringlen(osname);
    printf("Length: %d\n", len);
}