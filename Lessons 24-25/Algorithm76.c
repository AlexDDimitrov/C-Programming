#include <stdio.h>
#define max_students 30
#define max_subjects 20
//students' grades table 
void main()
{
    int n, m, i, j;
    float avr = 0;
    int marks[max_students][max_subjects];
    
    do {
        printf("Enter the number of students: ");
        scanf("%d", &n);
    } while (n <= 0 || n > max_students);

    do {
        printf("Enter the number of subjects: ");
        scanf("%d", &m);
    } while (m <= 0 || m > max_subjects);

    for(i=0; i < n; i++) {
        printf("Enter marks for student %d:\n", i + 1);
        for(j = 0; j < m; j++) {
            do{
                printf("Enter marks for subject %d: ", j + 1);
                scanf("%d", &marks[i][j]);
            }while(marks[i][j] < 2 || marks[i][j] > 6);
        }
    }
    printf("\nMarks entered:\n");
    printf("Subjects:   ");
    for(j = 0; j < m; j++) {
        printf("%d    ", j + 1);
    }
    printf("Average: ");
    printf("\n");
    for(i = 0; i < n; i++) {
        printf("Student %d:  ", i + 1);
        for(j = 0; j < m; j++) {
            avr += marks[i][j];
            printf("%d    ", marks[i][j]);
        }
        printf("%.2f", avr / m);
        avr = 0;
        printf("\n");
    }
    printf("Average:    ");
    for(j = 0; j < m; j++) {
        avr = 0;
        for(i = 0; i < n; i++) {
            avr += marks[i][j];
        }
        printf("%.2f ", avr / n);
    }

    avr = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            avr += marks[i][j];
        }
    }
    printf("%.2f", avr / (n * m));

}