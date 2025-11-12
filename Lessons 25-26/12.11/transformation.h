#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#define ERROR_SIZE 100

typedef struct {
    long result;
    char error[ERROR_SIZE];
} transformation;

transformation string_to_long(char *input);

#endif
