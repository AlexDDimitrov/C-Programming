#include <stdio.h>
#include <string.h>
// текуща дължина//
int main(){
    char str[21];
    int i, len = 0;
    char *p;
    printf("Enter the string: ");
    fgets(str, 21, stdin);
    if(p = strchr(str, '\n')) *p = '\0'; 

    for (i=0; str[i]; i++) len++;
    printf("%d", len);

    printf("\n%d", strlen(str));

    printf("\n%d", sizeof(str));
    return 0;
}