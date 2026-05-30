#ifndef TYPES_H
#define TYPES_H

#define MAX_NAME 255

typedef enum {
    NONE = 0,
    BASIC = 1,
    MIDDLE = 2,
    HIGH = 3
} Education;

typedef enum {
    UNEMPLOYED = 0,
    EMPLOYED = 1
} Working;

typedef enum {
    SINGLE = 0,
    MARRIED = 1
} Married;

typedef struct {
    char egn[11];
    unsigned char name_len;
    char name[MAX_NAME];
    unsigned char age;
    unsigned char education;
    unsigned char working;
    unsigned char married;
} Person;

#endif