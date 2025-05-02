#include <stdio.h>
#include <string.h>
// remove extra spaces from a string//
int main() {
    char s1[100];
    int i, j = 0;

    printf("Enter a string:\n");
    fgets(s1, 100, stdin);

    i = 0;
    while (s1[i] == ' ') {
        i++;
    }

    for (; s1[i] != '\0'; i++) {
        if (s1[i] != ' ' || s1[i + 1] != ' ') {
            s1[j++] = s1[i];
        }
    }

    if (j > 0 && s1[j - 1] == ' ') {
        j--;
    }
    s1[j] = '\0';

    printf("%s\n", s1);
    
}