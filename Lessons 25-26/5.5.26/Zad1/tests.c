#include <stdio.h>
#include <string.h>
#include "LinkedLists.h"
#include "task.h"

const char * statusToString(TaskStatus status) {
    switch (status) {
        case NEW: return "New";
        case IN_PROGRESS: return "In Progress";
        case DONE: return "Done";
    }
    return "Unknown";
}

void addTaskWithPriority(LinkedList * list, const char * name, int priority) {
    Task t;
    strcpy(t.name, name);
    t.status = NEW;

    if (priority < 1) priority = 1;
    if (priority > list->size + 1) priority = list->size + 1;

    push(list, priority - 1, t);
}

void changeTaskStatus(LinkedList * list, int priority, TaskStatus status) {
    if (priority < 1 || priority > list->size) return;

    Task t = get(list, priority - 1);
    t.status = status;
    set(list, priority - 1, t);
}

void deleteTask(LinkedList * list, int priority) {
    if (priority < 1 || priority > list->size) return;
    pop(list, priority - 1);
}

void printTasks(LinkedList * list) {
    for (int i = 0; i < list->size; i++) {
        Task t = get(list, i);
        printf("%d. %s [%s]\n", i + 1, t.name, statusToString(t.status));
    }
}

int main() {
    LinkedList tasks = init();

    addTaskWithPriority(&tasks, "Clean room", 1);
    addTaskWithPriority(&tasks, "Buy groceries", 2);
    addTaskWithPriority(&tasks, "Write homework", 2);

    printf("List of tasks\n");
    printTasks(&tasks);

    printf("\nChanging status of task 2\n");
    changeTaskStatus(&tasks, 2, IN_PROGRESS);
    printTasks(&tasks);

    printf("\nDeleting task 1\n");
    deleteTask(&tasks, 1);
    printTasks(&tasks);

    release(&tasks);
    return 0;
}
