#include <stdio.h>
#include <string.h>

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
    
    if (strlen(str2) > strlen(str3)) {
        while (pstr) {
            strncpy(pstr, str3, strlen(str3));
            pstr = strstr(pstr + strlen(str3), str2);
        }
    }

    pstr = strstr(str, str2);
    while (pstr) {
        strncpy(pstr, str3, strlen(str3));
        pstr = strstr(pstr + strlen(str3), str2);
    }
    printf("The new string is: %s\n", str);
    return 0;
}