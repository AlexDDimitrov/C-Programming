#include <stdio.h>
#include <string.h>

int main(){
    char str[21];
    char str2[21];
    int i;
    int found = 0;
    char *p, *pstr;
    printf("Enter the string: ");
    fgets(str, 21, stdin);
    if(p = strchr(str, '\n')) *p = '\0'; 

    printf("Enter the string you want to find: ");
    fgets(str2, 21, stdin);
    if(p = strchr(str2, '\n')) *p = '\0';
    pstr = strstr(str, str2);
    while (pstr) {
        found++;
        pstr = strstr(pstr + strlen(str2), str2);
    }
    if(found == 0) printf("Not found\n");
    else printf("Found %d times\n", found);
    return 0;
}