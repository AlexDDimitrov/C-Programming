#include <stdio.h>
#include <string.h>
//search and replace//
int main(){
    char str[21];
    char str2[21];
    char str3[21];

    int i, m;
    int found = 0;
    char *p, *pstr;
    printf("Enter the string: ");
    fgets(str, 21, stdin);
    if(p = strchr(str, '\n')) *p = '\0'; 

    printf("Enter the string you want to find: ");
    fgets(str2, 21, stdin);
    if(p = strchr(str2, '\n')) *p = '\0';

    printf("Enter the string you want to replace with: ");
    fgets(str3, 21, stdin);
    if(p = strchr(str3, '\n')) *p = '\0';

    pstr = strstr(str, str2);
    do {
        if(pstr = strstr(pstr, str2)) {
            strcat(str3, pstr + strlen(str2));
        }
    } while(pstr);
    printf("The new string is: %s\n", str);
    return 0;
}