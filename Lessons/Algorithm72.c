#include <stdio.h>
#include <string.h>
// most letters in a row//
int main() {
    char s[20], max_char;
    int max_count = 0, current_count = 1;

    fgets(s, 20, stdin);
    char *pos;
    if ((pos = strchr(s, '\n'))) *pos = '\0'; 

    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            current_count++; 
        } else {
            if (current_count > max_count) {
                max_count = current_count; 
                max_char = s[i - 1];   
            }
            current_count = 1;
        }
    }

    if (current_count > max_count) {
        max_count = current_count;
        max_char = s[strlen(s) - 1];
    }

    printf("%d%c\n", max_count, max_char);
    return 0;
}