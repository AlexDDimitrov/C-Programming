#include <stdio.h>
#include <string.h>
char str[100];
void checkValue() {
    int biggestValue = str[0];
    for (int i = 0; str[i] != '\0'; i++)
    {
        int a = str[i];
        if(a > biggestValue) {
            biggestValue = a;
        }
    }
    char max = biggestValue;
    printf("%c", max);
}

int main() {   
    fgets(str, 100, stdin);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '\n') str[i] = '\0';
    }
    
    checkValue();
    return 0;
}