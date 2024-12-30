#include <stdio.h>
//да се изведе кой ден от годината е//
void main()
{
int day, month, year;
int daysInMonth;
int vis;
int nextDay;
int nextMonth;
int nextYear;
do{
        printf("Enter the day = ");
        scanf("%d", &day);
        printf("Enter the month = ");
        scanf("%d", &month);
        printf("Enter the year = ");
        scanf("%d", &year);

        if (year%4==0)
        {
            if(year%100) vis=1;
            else
                if(year%400) vis=0;
                else vis=1;
        }
        else vis=0;
        switch (month)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: daysInMonth=31; break;
            case 4: case 6: case 9: case 11: daysInMonth=30; break;
            case 2: daysInMonth=28+vis; break;
        }
    } while (year<0 || month<1 || month>12 || day<1 || day>daysInMonth);
    int prevDay = day - 1;
    int prevMonth = month;
    int prevYear = year;

    if (prevDay < 1) 
        {
        prevMonth--;
        if (prevMonth < 1) 
        switch (prevMonth)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: daysInMonth=31; break;
            case 4: case 6: case 9: case 11: daysInMonth=30; break;
            case 2: daysInMonth=28+vis; break;
        }
        prevDay = daysInMonth;
        }
    

    nextDay = day + 1;
    nextMonth = month;
    nextYear = year;

    if (nextDay > daysInMonth) {
        nextDay = 1;
        nextMonth++;
        if (nextMonth > 12) 
        {
            nextMonth = 1;
            nextYear++;
        }
    }

    printf("Previous day: %d-%d-%d\n", prevDay, prevMonth, prevYear);
    printf("Next day: %d-%d-%d\n", nextDay, nextMonth, nextYear);


}