#include <stdio.h>

#define COMMAND(NAME, TYPE) TYPE##_##NAME##_command

#define DEFINE_COMMAND(NAME, TYPE) void COMMAND(NAME, TYPE)()

DEFINE_COMMAND(quit, internal) {
    printf("QUIT\n");
}

DEFINE_COMMAND(start, internal) {
    printf("START\n");
    printf("\n");
}

int main() {
    COMMAND(start, internal)();
    COMMAND(quit, internal)();
    return 0;
}