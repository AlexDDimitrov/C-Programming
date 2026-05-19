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
        printf("1. Change value of 2 numbers\n");
        if (a == 2) printf(">");
        else printf(" ");
        printf("2. Add from 1 to n numbers\n");
        if (a == 3) printf(">");
        else printf(" ");
        printf("3. Day of week\n");
        if (a == 4) printf(">");
        else printf(" ");
        printf("4. \n");
        if (a == 5) printf(">");
        else printf(" ");
        printf("5. \n");
        if (a == 6) printf(">");
        else printf(" ");
        printf("6. \n");
        if (a == 7) printf(">");
        else printf(" ");
        printf("7. \n");
        if (a == 8) printf(">");
        else printf(" ");
        printf("8. \n");
        if (a == 9) printf(">");
        else printf(" ");
        printf("9. \n");
        if (a == 10) printf(">");
        else printf(" ");
        printf("10. Quit\n");

        c = getch();

        if (c == -32 || c == 224)
        {
            c = getch(); 
            if (c == 72) a--; 
            if (c == 80) a++; 
        }

        if (a > 10) a = 1;
        if (a < 1) a = 5;

        if (c == '\r')
        {
            switch (a)
            {
            case 1:
                int a1, b1, c1;
                printf ("a = ");
                scanf("%d", &a1);
                printf ("b = ");
                scanf("%d", &b1);
                c1=a1;
                a1=b1;
                b1=c1;
                printf("a=%d, b=%d", a1, b1);
                printf("\n");
                break;
            case 2:
                int a2, s2, n2, i2;
                printf ("n = ");
                scanf("%d", &n2);
                while (n2<1)
                {
                    printf ("n = ");
                    scanf("%d", &n2);
                }
                s2=0;
                i2=1;
                while (i2<=n2)
                {
                    s2=s2+i2;
                    i2++;
                }
                printf("sum = %d", s2);
                printf("\n");
                break;
            case 3:
    int day, month, year;
    int daysInMonth;
    int vis, i3, den_num = 0;
    char daysOfWeek;
    
    do {
        printf("Enter the day = ");
        scanf("%d", &day);
        printf("Enter the month = ");
        scanf("%d", &month);
        printf("Enter the year = ");
        scanf("%d", &year);

        
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) vis = 1;
                else vis = 0;
            } else vis = 1;
        } else vis = 0;

        
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: daysInMonth = 31; break;
            case 4: case 6: case 9: case 11: daysInMonth = 30; break;
            case 2: daysInMonth = 28 + vis; break;
            default: daysInMonth = 0; break;
        }
    } while (year < 0 || month < 1 || month > 12 || day < 1 || day > daysInMonth);


    for (i3 = 1; i3 < month; i3++) {
        switch (i3) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: den_num += 31; break;
            case 4: case 6: case 9: case 11: den_num += 30; break;
            case 2: den_num += 28 + vis; break;
        }
    }
    den_num += day;


    int totalDays = den_num;
    for (i3 = 1; i3 < year; i3++) {
        if (i3 % 4 == 0 && (i3 % 100 != 0 || i3 % 400 == 0)) {
            totalDays += 366; 
        } else {
            totalDays += 365; 
        }
    }
    int dayOfWeek = (totalDays - 1) % 7; 


    switch (dayOfWeek)
    {
        case 1:
            printf("Tuesday");
            break;
        case 2:
            printf("Wednesday");
            break;
        case 3:
            printf("Thursday");
            break;
        case 4:
            printf("Friday");
            break;
        case 5:
            printf("Saturday");
            break;
        case 6:
            printf("Sunday");
            break;
        case 0: case 7:
            printf("Monday");
            break;
        default:
            printf("Invalid");
    }
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                m=1;
                break;
            }
            if (a != 10)
            {
                printf("Press any key to continue...\n");
                getch();
            }
        }

    } while (m==0);

    return 0;
}
