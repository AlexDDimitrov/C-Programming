#include <stdio.h>

#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_TITLE_LENGTH 100
#define MAX_PARTICIPANTS_NUMBER 100

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char middleName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Participant;

typedef enum Boolean {
    TRUE = 1,
    FALSE = 0
} Boolean;

typedef struct {
    Participant participant;
    Boolean isParticipating;
} Participants;

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_TITLE_LENGTH * 2];
    struct {
        int day;
        int month;
        int year;
        struct {
            int hour;
            int minute;
        } time;
    } date;
    Participants answers[MAX_PARTICIPANTS_NUMBER];
    int answerCount;
} Cause;

void printParticipant(Participant p) {
    printf("Participant: %s %s %s\n", p.firstName, p.middleName, p.lastName);
    printf("Mail: %s\n", p.email);
    printf("Telephone: %s\n", p.phone);
}

void printParticipantAnswer(Participants pa) {
    printParticipant(pa.participant);
    printf("Will take part: %s\n", pa.isParticipating ? "Yes" : "No");
}

void printDate(void* d) {
    typedef struct{
        int day;
        int month;
        int year;
        struct {
            int hour;
            int minute;
        } time;
    } days;
    days* day= d;
    printf("Date: %02d.%02d.%d %02d:%02d\n",
           day->day, day->month, day->year, day->time.hour, day->time.minute);
}

void printCause(Cause c) {
    printf("\nCause \n");
    printf("Title: %s\n", c.title);
    printf("Description: %s\n", c.description);
    printDate(&c.date);
    printf("Participants (%d):\n", c.answerCount);

    for (int i = 0; i < c.answerCount; i++) {
        printf("№%d:\n", i + 1);
        printParticipantAnswer(c.answers[i]);
    }
}

int main(void) {
    Participant alex = { "Alex", "Dimitrov", "Dimitrov", "alex@gmail.com", "08787587385" };
    Participant eli  = { "Eli",  "Dimitrova", "Dimitrova", "eli@gmail.com",  "09585589426" };
    Participant teo  = { "Teo",  "Dimitrov",  "Dimitrov",  "teo@gmail.com",  "08997114934" };

    Cause saveAnimals = {
        .title = "Save the animals",
        .description = "Help pls to save the animals",
        .date = { 
            .day = 24,
            .month = 3,
            .year = 2026,
            .time = { 9, 0 }
        },
        .answers = {
            { alex, TRUE },
            { eli, FALSE }
        },
        .answerCount = 2
    };

    Cause savePlanet = {
        "Save the planet",
        "Help pls to save the planet",
        { 25, 5, 2026, { 14, 0 } },
        {
            { eli, TRUE },
            { teo, FALSE }
        },
        2
    };

    printCause(saveAnimals);
    printCause(savePlanet);

    return 0;
}
