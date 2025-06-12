#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//menu//
int main()
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
        printf("1. Enter addresses\n");
        if (a == 2) printf(">");
        else printf(" ");
        printf("2. Delete addresses\n");
        if (a == 3) printf(">");
        else printf(" ");
        printf("3. Show the list\n");
        if (a == 4) printf(">");
        else printf(" ");
        printf("4. Print the list\n");
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
                printf("Enter the number of addresses: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    printf("Enter address: ");
                    scanf("%d", &j);
                }
                break;
            case 2:
                printf("Deleting addresses...\n");
                break;
            case 3:
                printf("List:\n");
                printf("1. 10101011\n");
                printf("2. 11001100\n");
                printf("3. 00110101\n");
                printf("4. 11110000\n");
                printf("5. 10100101\n");
                printf("6. 10011011\n");
                printf("7. 11000011\n");
                printf("8. 01100110\n");
                printf("9. 01010110\n");
                printf("10. 00011110\n");
                break;
            case 4:
                printf("Printing the list...\n");
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
