#include <stdio.h>
#include <string.h>

typedef struct{
    int num;
    char name[20];
    int marks[20];
    float avr;
} Tstudent;

Tstudent st;

int main() {
    Tstudent students[30];
    int n, i, j, m;
    char *p;

    do{
        printf("Enter number of students (<=30): ");
        scanf("%d", &n);
    } while (n < 1 || n > 30);
    
    st.avr = 0;

    do {
        printf("Enter number of subjects (<=20): ");
        scanf("%d", &m);
    } while (m < 1 || m > 20);
    getchar();

    for (i = 0; i < n; i++) {       

        printf("Enter student name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        if ((p = strchr(students[i].name, '\n'))) *p = '\0';
        students[i].num = i + 1;
        for (j = 0; j < m; j++) {
            do {
                printf("Enter mark %d: ", j + 1);
                scanf("%d", &students[i].marks[j]);
            } while (students[i].marks[j] < 0 || students[i].marks[j] > 6);
            getchar();
            students[i].avr += students[i].marks[j];
        }
        students[i].avr /= m;
    }

    printf("\nMarks entered:\n");
    printf("Subjects:   ");
    for (j = 0; j < m; j++) {
        printf("%d    ", j + 1);
    }
    printf("Average:\n");

    for (i = 0; i < n; i++) {
        printf("%d %s :  ", i + 1, students[i].name);
        float avr = 0;
        for (j = 0; j < m; j++) {
            printf("%d    ", students[i].marks[j]);
            avr += students[i].marks[j];
        }
        printf("%.2f\n", avr / m);
    }

    printf("Average:    ");
    for (j = 0; j < m; j++) {
        float avr = 0;
        for (i = 0; i < n; i++) {
            avr += students[i].marks[j];
        }
        printf("%.2f ", avr / n);
    }

    float total_avr = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            total_avr += students[i].marks[j];
        }
    }
    printf("%.2f\n", total_avr / (n * m));

    return 0;
}
