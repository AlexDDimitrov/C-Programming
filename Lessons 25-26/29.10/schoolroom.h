#ifndef SCHOOLROOM_H
#define SCHOOLROOM_H
#ifndef PERSON_H
#include "person.h"
#endif

typedef struct {
    int roomNumber;
    Person occupants[50];
} SchoolRoom;

#endif