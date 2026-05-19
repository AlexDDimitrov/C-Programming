#include <stdio.h>
#include <string.h>
#define MAX 251
// brackets 
int main() {
    char c[MAX];
    int a[125][2];
    char *p;
    int j, i = 0, br = 0;

    printf("Enter string: ");
    fgets(c, MAX, stdin);
    if ((p = strchr(c, '\n'))) *p = '\0';

    if (strchr(c, '(') && strchr(c, ')')) {
        for (i = 0; c[i]; i++) {
            if(c[i] != '(' && c[i] != ')' && c[i] != '\0') {
                break;
            }
        }

        i=0;
        while (c[i]) {
            if (c[i] == '(') br++;
            else if (c[i] == ')') br--;
            if (br < 0) {
                break;
            }
            i++;
        }

        if (br != 0) {
            break;
        }
        


        br = 0;
        for (i = 0; c[i]; i++) {
            if (c[i] == ')') {
                j = i - 1;
                while (j >= 0 && c[j] != '(') {
                    j--;
                }
                if (j >= 0) {
                    a[br][0] = j + 1;
                    a[br][1] = i + 1;
                    br++;
                    c[j] = ' ';
                }
            }
        }
        int temp[2];
        for (i = 0; i < br - 1; i++) {
            for (j = 0; j < br - 1 - i; j++) {
                if (a[j][0] > a[j + 1][0]) {
                    temp[0] = a[j][0];
                    temp[1] = a[j][1];
                    a[j][0] = a[j + 1][0];
                    a[j][1] = a[j + 1][1];
                    a[j + 1][0] = temp[0];
                    a[j + 1][1] = temp[1];
                }
            }
        }
        for (i = 0; i < br; i++) {
            printf("%d, %d\n", a[i][0], a[i][1]);
        }
    }
    printf("Invalid brackets\n");
    return 0;
}
