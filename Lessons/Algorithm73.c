#include <stdio.h>
#include <string.h>
//longest word in a string//
int main() {
    char s1[100], s2[100], max_word[100];
    char *pos;
    int current_len = 0, max_len = 0;
    int i, j;

    fgets(s1, 100, stdin);
    if(pos = strchr(s1, '\n')) *pos = '\0'; 

    for (i = 0, j = 0; s1[i]; i++, j++) {
        if (s1[i] != ' ') { 
            s2[j] = s1[i];
            current_len++;
        } else {  
            if (current_len > max_len) {
                max_len = current_len;
                s2[j] = '\0'; 
                strcpy(max_word, s2);  
            }
            current_len = 0;  
            j = -1;  
        }
    }

   
    if (current_len > max_len) {
        max_len = current_len;
        s2[j] = '\0'; 
        strcpy(max_word, s2);
    }

    printf("Longest word: %s\n", max_word);

    return 0;
}