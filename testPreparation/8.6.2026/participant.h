#ifndef PARTICIPANT_H
#define PARTICIPANT_H

typedef unsigned int uint;

#define MAX_LENGTH 100

typedef struct Participant {
    uint number;
    uint timeInMinutes;
    char firstName[MAX_LENGTH];
    char secondName[MAX_LENGTH];
    char thirdName[MAX_LENGTH];
} Participant;

#define FILE_NAME "leaderboard.txt"
#define CSV_FILE_NAME "leaderboard.csv"
#define BIN_FILE_NAME "leaderboard.bin"

#endif