#include <stdio.h>
#include <string.h>

int main(void)
{
    char a; 
    int c, n, i;

    printf("Mailing list menu\n");
    printf("1. Enter addresses\n");
    printf("2. Delete addresses\n");
    printf("3. Seaech the list\n");
    printf("4. Print the list\n");
    printf("5. Quit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c)
        {
            case 1:
                printf("Number of addresses\n");
                scanf("%d", &n);
                for ( i = 0; i<n; i++)
                {
                    printf("Enter address\n");
                    scanf("%ld", &a);
                }
                break;
            case 2:
                printf("Delete addresses\n");
                break;
            case 3:
                printf("List:\n");
                printf("1. email1.gmail.com\n");
                printf("2. email2.gmail.com\n");
                printf("3. email3.gmail.com\n");
                printf("4. email4.gmail.com\n");
                printf("5. email5.gmail.com\n");
                printf("6. email6.gmail.com\n");
                printf("7. email7.gmail.com\n");
                printf("8. email8.gmail.com\n");
                printf("9. email9.gmail.com\n");  
                printf("10. email10.gmail.com\n");
                break;
            case 4:
                printf("Printing the list\n");
                break;
            case 5:
                printf("Quit\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (c < 1 || c > 5 || c != 5);

    return 0;
}