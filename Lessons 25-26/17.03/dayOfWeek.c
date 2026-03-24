#include <stdio.h>

enum Weekdays{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(void) {
    int day;

    printf("Enter number of day 1-7: ");
    scanf("%d", &day);

    enum Weekdays dayOfWeek = day;
    switch(dayOfWeek) {
        case 1: printf("Monday"); break;
        case 2: printf("Tuesday"); break;
        case 3: printf("Wednesday"); break;
        case 4: printf("Thursday"); break;
        case 5: printf("Friday"); break;
        case 6: printf("Saturday"); break;
        case 7: printf("Sunday"); break;
        default: printf("Invalid!"); break;
    }

}