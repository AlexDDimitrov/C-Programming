#include <stdio.h>
#include "processes.h"

Process processes[MAX_PROCESSES];
int processescount = 0;
static int lastid = 0;

static int nextprocessid() {
    //static int lastid = 0;

    if (lastid == INT_MAX) {
        return 0;
    }

    lastid++;
    int newid = lastid;
    return newid;
}

int createnewprocess(const char *name) {
    if (processescount >= MAX_PROCESSES) {
        return 0;
    }

    int id = nextprocessid();
    if (id == 0) {
        return 0;
    }

    processes[processescount].id = id;
    strncpy(processes[processescount].name, name, 30);

    processescount++;
    return id;
}

void stopprocess(int id) {
    int notValidID = -1;

    for (int i = 0; i < processescount; i++) {
        if (processes[i].id == id) {
            notValidID = i;
            break;
        }
    }

    if (notValidID == -1) {
        return;
    }

    for (int i = notValidID; i < processescount - 1; i++) {
        processes[i] = processes[i + 1];
        processes[i].id--;
    }   
    lastid--;
    processescount = processescount - 1;
}