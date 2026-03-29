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
}

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

void printCause(Cause* cause) {
    printf("\n============================\n");
    printf("Cause: %s\n", cause->title);
    printf("Description: %s\n", cause->description);
    printDate(cause->date);
    printf("Participants %d:\n", cause->answerCount);

    for (int i = 0; i < cause->answerCount; i++) {
        printf("№ %d:\n", i + 1);
        printParticipantAnswer(cause->answers[i]);
    }
}

int main(void) {
    Participant alex = { "Alex", "Dimitrov", "Dimitrov", "alex@gmail.com", "08787587385" };
    Participant eli = { "Eli", "Dimitrova", "Dimitrova", "eli@gmail.com", "09585589426" };
    Participant teo = { "Teo", "Dimitrov", "Dimitrov", "teo@gmail.com", "08997114934" };

    Cause saveAnimals = {
        .title = "Save the animals",
        .description = "Help save the animals",
        .date = { 
            .day = 24,
            .month = 3,
            .year = 2026,
            .time = {
                .hour = 9,
                .minute = 00
            }    
        },
        .answers = {
            { alex, TRUE },
            { eli, FALSE },
        },
        .answerCount = 2
    };

    Cause savePlanet = {
        "Save the planet",
        "Help save the planet",
        { 25, 5, 2026, { 14, 0 } },
        {
            { p2, TRUE },
            { p3, FALSE }
        },
        2
    };


}