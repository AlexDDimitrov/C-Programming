#ifndef PROCESSES_H
#define PROCESSES_H
#include <limits.h>
#include <string.h>

typedef struct {
    int id;
    char name[31];
} Process;

#define MAX_PROCESSES 5
extern Process processes[MAX_PROCESSES];
extern int processescount;

int createnewprocess(const char *name);
void stopprocess(int id);

#endif