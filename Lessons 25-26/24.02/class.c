#include <stdio.h>
#include <stdlib.h>

char* enterStr() {
    char current = '\0';
    char* line = NULL;
    size_t size = 0;

    do {
        current = getchar();
        size++;

        char* currentLine = realloc(line, size * sizeof(char));
        if (currentLine == NULL) {
            free(line);
            printf("Error allocating memory!");
            exit(1);
        }

        line = currentLine;
        line[size - 1] = current;

    } while (current != '\n' && size < 15);

    line[size - 1] = '\0';
    return line;
}

int main(void) {
    int c = 0;

    do {
        printf("Please enter the number of subjects: ");
        scanf("%d", &c);
    } while (c < 1);

    getchar();

    char** p = malloc(c * sizeof(char*));

    for (int i = 0; i < c; i++) {
        printf("Enter subject %d: ", i + 1);
        p[i] = enterStr();
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < c; i++) {
        printf("Subject %d: %s\n", i + 1, p[i]);
    }

    for (int i = 0; i < c; i++) {
        free(p[i]);
    }

    free(p);
    return 0;
}
