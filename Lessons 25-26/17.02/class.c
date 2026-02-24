#include <stdio.h>
#include <stdlib.h>

#define ALLOC_CHECKING(ptr) \
    if (ptr == NULL) { \
        printf("Memory allocation failed\n"); \
        exit(1); \
    }

float calcAvr(float * grades, int n) {
    if (n == 0) {
        return 0;
    }
    float sum = 0;
    for (int i = 0; i < n; i++) {
        if(grades!=NULL) {
            sum += grades[i];
        }
    }
    return sum / n;
}

int main(void) {

    int n = 0;
    while(n==0) {
        printf("Enter a number: ");
        scanf("%d", &n);
    }

    float * grades = (float *) malloc(n * sizeof(float));
    if (grades == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%f", &grades[i]);
    }

    int choice = 0;
    do {
        printf("1. Print average\n");
        printf("2. Add new grade\n");
        printf("3. Delete last grade\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (n == 0) {
                printf("No grades to average\n");
            } else {
                printf("Average: %.2f\n", calcAvr(grades, n));
            }
            break;
        case 2: {
                float new_grade;
                printf("Enter a new grade: ");
                scanf("%f", &new_grade);
                float * temp = (float *) realloc(grades, (n + 1) * sizeof(float));
                ALLOC_CHECKING(temp);
                grades = temp;
                grades[n] = new_grade;
                n++;
                printf("Grade added\n");
                break;
            }
        case 3:
            if (n == 0) {
                printf("No grades to delete\n");
            } else {
                float* temp = (float *) realloc(grades, (n - 1) * sizeof(float));
                ALLOC_CHECKING(temp);
                grades = temp;
                n--;
                printf("Last grade deleted\n");
            }
            break;
        case 4:
            printf("Exiting\n");
            break;

        default:
            break;
        }
    } while (choice != 4);
    
    free(grades);
    return 0;
}