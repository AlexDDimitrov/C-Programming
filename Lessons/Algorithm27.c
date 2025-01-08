#include <stdio.h>

void main() {
    int day, month, year;
    int daysInMonth;
    int vis, i, den_num = 0;
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


    for (i = 1; i < month; i++) {
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: den_num += 31; break;
            case 4: case 6: case 9: case 11: den_num += 30; break;
            case 2: den_num += 28 + vis; break;
        }
    }
    den_num += day;


    int totalDays = den_num;
    for (i = 1; i < year; i++) {
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
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
}