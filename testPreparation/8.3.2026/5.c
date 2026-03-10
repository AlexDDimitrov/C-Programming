#include <stdio.h>
#include <stdlib.h>

char* ReadLine() {

    int size = 0;
    char* name = malloc(size*sizeof(char));
    if (name == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    do {
        size++;
        char* temp = realloc(name, size*sizeof(char));
        if (temp == NULL) {
            printf("Memory allocation error!\n");
            free(name);
            exit(1);
        }
        name = temp;
        name[size-1] = getchar(); 
    } while(name[size-1] != '\n');
    name[size-1] = '\0';
    return name;
}

int main(void) {
    int number;
    printf("Enter amount: ");
    scanf("%d", &number);
    getchar();

    char** names = malloc(number * sizeof(char*));
    if (names == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    for (int i = 0; i < number; i++) {
        printf("Enter name %d: ", i + 1);
        names[i] = ReadLine();
    }

    for (int i = 0; i < number; i++) {
        printf("%s ", names[i]);
    }
}