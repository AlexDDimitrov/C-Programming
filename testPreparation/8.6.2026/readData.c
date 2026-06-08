#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "participant.h"

void read_TXT(FILE * file) {
    Participant p;
    while(fscanf(file, "%u %u %s %s %s", &p.number, &p.timeInMinutes, p.firstName, p.secondName, p.thirdName) == 5) {
        printf("%u %u %s %s %s\n", p.number, p.timeInMinutes, p.firstName, p.secondName, p.thirdName);
    }
}

#define MAX_LENGTH_CSV ((MAX_LENGTH * 3) + sizeof(uint) * 2 + 10)

void read_CSV(FILE * file) {
    Participant p;
    char line[MAX_LENGTH_CSV];
    while(fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        line[strcspn(line, "\r")] = '\0';
        char * token = strtok(line, ",");
        if (token == NULL) {
            exit(1);
        }
        p.number = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            exit(1);
        }
        p.timeInMinutes = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            exit(1);
        }
        strcpy(p.firstName, token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            exit(1);
        }
        strcpy(p.secondName, token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            exit(1);
        }
        strcpy(p.thirdName, token);

        printf("%u,%u,%s,%s,%s\n", p.number, p.timeInMinutes, p.firstName, p.secondName, p.thirdName);
    }
}

void read_BIN(FILE * file) {
    Participant p;
    while (fread(&p.number, sizeof(uint), 1, file) &&
    fread(&p.timeInMinutes, sizeof(uint), 1, file) &&
    fread(p.firstName, MAX_LENGTH, 1, file) &&
    fread(p.secondName, MAX_LENGTH, 1, file) &&
    fread(p.thirdName, MAX_LENGTH, 1, file)) {
        printf("BIN: %u %u %s %s %s\n", p.number, p.timeInMinutes, p.firstName, p.secondName, p.thirdName);
    }
}

int main(void) {
    FILE * file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("ERROR");
        exit(1);
    }
    read_TXT(file);
    fclose(file);

    file = fopen(CSV_FILE_NAME, "r");
    if (file == NULL) {
        printf("ERROR");
        exit(1);
    }
    read_CSV(file);
    fclose(file);

    file = fopen(BIN_FILE_NAME, "rb");
    if (file == NULL) {
        printf("ERROR");
        exit(1);
    }
    read_BIN(file);
    fclose(file);
}