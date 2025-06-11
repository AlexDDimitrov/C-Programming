#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Students with grades above 5.50 and below 3

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
    //Printing students with grades above 5.50 and below 3
    printf("Students with grade above 5.50 \n");
    for(i=0; i<n; i++)
    {
        if(class[i].avr >= 5.50)
        {
            printf("%s   ", class[i].name);
            for(j=0; j < m; j++)
            {
                printf("%d ,", class[i].marks[j]);
            }
            printf("Average: ");
            printf("%.2f", class[i].avr);
        }
    }

    printf("\nStudents with grade bellow 3 \n");
    for(i=0; i<n; i++)
    {
        if(class[i].avr <= 3)
        {
            printf("%s   ", class[i].name);
            for(j=0; j < m; j++)
            {
                printf("%d ,", class[i].marks[j]);
            }
            printf("Average: ");
            printf("%.2f", class[i].avr);
        }
    }

    return 0;
}

