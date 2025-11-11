#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H
#ifndef PERSON_H
#include "person.h"
#endif

typedef struct {
    Person students[26];
    char classLetter;
    int classNumber;
    Person classTeacher;
} SchoolClass;

#endif