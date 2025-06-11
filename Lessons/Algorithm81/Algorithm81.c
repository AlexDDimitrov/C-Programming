#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//menu//
int main(void)
{
    int a = 1; 
    int n, m, i, j;
    char c;
    m=0;
    do
    {
        system("cls");
        printf(" Menu\n");
        if (a == 1) printf(">");
        else printf(" ");
        printf("1. Choose file\n");
        if (a == 2) printf(">");
        else printf(" ");
        printf("2. Write on file\n");
        if (a == 3) printf(">");
        else printf(" ");
        printf("3. Read file\n");
        if (a == 4) printf(">");
        else printf(" ");
        printf("4. Add on file\n");
        if (a == 5) printf(">");
        else printf(" ");
        printf("5. Quit\n");

        c = getch();

        if (c == -32 || c == 224)
        {
            c = getch(); 
            if (c == 72) a--; 
            if (c == 80) a++; 
        }

        if (a > 5) a = 1;
        if (a < 1) a = 5;

        if (c == '\r')
        {
            switch (a)
            {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                printf("Quitting...\n");
                m=1;
                break;
            }
            if (a != 5)
            {
                printf("Press any key to continue...\n");
                getch();
            }
        }

    } while (m==0);

    return 0;
}
