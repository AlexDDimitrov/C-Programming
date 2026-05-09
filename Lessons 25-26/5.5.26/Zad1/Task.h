#ifndef TASK_H
#define TASK_H

typedef enum {
    NEW,
    IN_PROGRESS,
    DONE
} TaskStatus;

typedef struct {
    char name[128];
    TaskStatus status;
} Task;

#endif