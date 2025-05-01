#include <stdio.h>
#include <string.h>
// replace spaces with new lines//
int main(){
    char str[101];
    char *p;

    printf("Enter name: ");
    fgets(str, 100, stdin);
    if(p = strchr(str, '\n')) *p = '\0'; 

    do {
        if(p = strchr(str, ' ')) *p = '\n';
    } while (p);

    printf("Your name is:\n%s\n", str);
}