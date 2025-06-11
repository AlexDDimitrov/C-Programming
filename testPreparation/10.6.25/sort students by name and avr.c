#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// sorting students by name and average grade

typedef struct {
    char name[20];
    int marks[20];
    float avr;
} student;
student class[20];

int main() {
    int n, m, i, j;
    char *p;
    do{
        printf("Enter number of students (<=20): ");
        scanf("%d", &n);
    }while(n < 1 || n > 20);

    do {
        printf("Enter number of subjects (<=20): ");
        scanf("%d", &m);
    } while (m < 1 || m > 20);
    getchar();
    //Entering student names and marks
    for(i=0; i<n; i++)
    {
        printf("Enter student name: ");
        fgets(class[i].name, sizeof(class[i].name), stdin);
        if ((p = strchr(class[i].name, '\n'))) *p = '\0';
        class[i].avr = 0;
        for(j=0; j<m; j++)
        {
            do{
                printf("Enter marks %d:", j + 1);
                scanf("%d", &class[i].marks[j]);
            }while(class[i].marks[j] < 2 || class[i].marks[j] > 6);
            class[i].avr += class[i].marks[j];
        }
        getchar();
        class[i].avr /= m;
    }

    // Sorting students by name
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(strcmp(class[i].name, class[j].name) > 0) {
                student temp = class[i];
                class[i] = class[j];
                class[j] = temp;
            }
        }
    }
    printf("\nSorted students by name:\n");
    for(i = 0; i < n; i++) {
        printf("%s  ", class[i].name);
        for(j = 0; j < m; j++) {
            printf("%d ", class[i].marks[j]);
        }
        printf("Average: %.2f\n", class[i].avr);
    }

    //sorting students by average grade
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(class[i].avr < class[j].avr) {
                student temp = class[i];
                class[i] = class[j];
                class[j] = temp;
            }
        }
    }
    printf("\nSorted students by average grade:\n");
    for(i = 0; i < n; i++) {
        printf("%s  ", class[i].name);
        for(j = 0; j < m; j++) {
            printf("%d ", class[i].marks[j]);
        }
        printf("Average: %.2f\n", class[i].avr);
    }
}