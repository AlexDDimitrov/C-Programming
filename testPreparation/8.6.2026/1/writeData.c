#include <stdio.h>
#include <stdlib.h>
#include "participant.h"

void write_TXT(Participant p, FILE * file) {
    fprintf(file, "%u %u %s %s %s\n", p.number, p.timeInMinutes, p.firstName, p.secondName, p.thirdName);
}

void write_CSV(Participant p, FILE * file) {
    fprintf(file, "%u,%u,%s,%s,%s\n", p.number, p.timeInMinutes, p.firstName, p.secondName, p.thirdName);
}

void write_BIN(Participant p, FILE * file) {
    fwrite(&p.number, sizeof(uint), 1, file);
    fwrite(&p.timeInMinutes, sizeof(uint), 1, file);
    fwrite(p.firstName, MAX_LENGTH, 1, file);
    fwrite(p.secondName, MAX_LENGTH, 1, file);
    fwrite(p.thirdName, MAX_LENGTH, 1, file);
}

#define SIZE 3

int main(void) {
    Participant participants[SIZE] = {
        {33, 20, "Alex", "Dimirov", "Dimitrov"},
        {67, 20, "Eli", "Dimirova", "Dimitrova"},
        {76, 20, "Teo", "Dimirov", "Dimitrov"}
    };

    FILE * file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("ERROR");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++) {
        write_TXT(participants[i], file);
    }
    fflush(file);
    fclose(file);

    file = fopen(CSV_FILE_NAME, "w");
    if (file == NULL) {
        printf("ERROR");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++) {
        write_CSV(participants[i], file);
    }
    fflush(file);
    fclose(file);

    file = fopen(BIN_FILE_NAME, "wb");
    if (file == NULL) {
        printf("ERROR");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++) {
        write_BIN(participants[i], file);
    }
    fflush(file);
    fclose(file);
}