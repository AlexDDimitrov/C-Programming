#include <stdio.h>
#include <string.h>

int main() {
    char str[100], str2[100];
    char *p;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    if ((p = strchr(str, '\n'))) *p = '\0';

    printf("Enter substring to find: ");
    fgets(str2, sizeof(str2), stdin);
    if ((p = strchr(str2, '\n'))) *p = '\0';

    // check how many times str2 appears in str
    int count = 0;
    char *pos = str;
    while ((pos = strstr(pos, str2)) != NULL) {
        count++;
        pos += strlen(str2); 
    }
    printf("The substring '%s' appears %d times in the string '%s'.\n", str2, count, str);

    return 0;
}