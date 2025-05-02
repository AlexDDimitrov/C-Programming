#include <stdio.h>
#include <string.h>
// replace spaces with new lines//
int main(){
    char str[101];
    char *p;
    int i = 0, j = 0;

    printf("Enter name: ");
    fgets(str, 100, stdin);
    if(p = strchr(str, '\n')) *p = '\0'; 

    while (str[i] == ' ') {
        i++;
    }

    for (; str[i] != '\0'; i++) {
        if (str[i] != ' ' || str[i + 1] != ' ') {
            str[j++] = str[i];
        }
    }

    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }
    str[j] = '\0';
    do{
        if(p=strchr(str, ' ')) {
            *p = '\n';
        }
    }while (p);
    printf("Your name is:\n%s\n", str);
}