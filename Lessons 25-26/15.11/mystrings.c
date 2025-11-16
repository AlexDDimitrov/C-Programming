#include <stdio.h>
#include "myStrings.h"

int strLength(char *str) {
    int l = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        l++;
    }
    return l;
}

char *strconcat(char *dest, char *src) {
    int i = 0;
    int j = 0;
    while (dest[i] != '\0') i++;
    while (src[j] != '\0') {
        dest[i++] = src[j++];
    }
    dest[i] = '\0';
    return dest;
}

int strcompare(char *str1, char *str2) {
    int i = 0;
    int compare = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {compare = -1; break;}
        if (str1[i] > str2[i]) {compare = 1; break;}
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') compare = 0;
    if (str1[i] == '\0') compare = -1;
    return compare;
}