#include <stdio.h>
#include <string.h>
//the length of the longest word in a string
int main() {
    char str[100];
    char *p;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    if ((p = strchr(str, '\n'))) *p = '\0';

    // check the longest word in str
    int max = 0, current = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            current = 0;
        } else {
            current++;
        }
        if (current > max) {
            max = current;
        }
    }

    printf("The length of the longest word in the string is: %d\n", max);
    return 0;
}