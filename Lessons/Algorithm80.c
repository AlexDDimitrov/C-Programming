#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
//menu with students struct//
void nameSort(int n, int m);
void avrSort(int n, int m);
void goodGrades(int n, int m);
void badGrades(int n, int m);

typedef struct{
    int num;
    char name[20];
    int marks[20];
    float avr;
} Tstudent;

Tstudent st;
Tstudent students[30];

int main()
{
    int menuSelection = 1; 
    int menuOption, numAddresses, i, address;
    char option;
    int exitMenu = 0;
    int n, j, m;
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
    printf("Press any key to continue...\n");
    getch();
    do
    {
        system("cls");
        printf("Menu\n");
        if (menuSelection == 1) printf(">");
        else printf(" ");
        printf("1. Sort students by their name\n");
        if (menuSelection == 2) printf(">");
        else printf(" ");
        printf("2. Sort students by their avarage mark\n");
        if (menuSelection == 3) printf(">");
        else printf(" ");
        printf("3. Students who have grade above 5,50\n");
        if (menuSelection == 4) printf(">");
        else printf(" ");
        printf("4. Students who have grade below 2,50\n");
        if (menuSelection == 5) printf(">");
        else printf(" ");
        printf("5. Quit\n");

        option = getch();

        if (option == -32 || option == 224)
        {
            option = getch(); 
            if (option == 72) menuSelection--; 
            if (option == 80) menuSelection++; 
        }

        if (menuSelection > 5) menuSelection = 1;
        if (menuSelection < 1) menuSelection = 5;

        if (option == '\r')
        {
            switch (menuSelection)
            {
            case 1:
                nameSort(n, m);
                break;
            case 2:
                avrSort(n, m);
                break;
            case 3:
                goodGrades(n, m);
                break;
            case 4:
                badGrades(n, m);
                break;
            case 5:
                printf("Quitting...\n");
                exitMenu = 1;
                break;
            }
            if (menuSelection != 5)
            {
                printf("Press any key to continue...\n");
                getch();
            }
        }

    } while (exitMenu == 0);

    return 0;
}


void nameSort(int n, int m) {
    int i, j;
    Tstudent temp;
    system("cls");
    printf("Sorting students by name...\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

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
}

void avrSort(int n, int m) {
    int i, j;
    Tstudent temp;
    system("cls");
    printf("Sorting students by average mark...\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].avr < students[j].avr) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
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
    
}

void goodGrades(int n, int m) {
    int i, j;
    system("cls");
    printf("Students with grades above 5.50:\n");
    for (i = 0; i < n; i++) {
        if (students[i].avr >= 5.50) {
            printf("%d %s : ", students[i].num, students[i].name);
            for (j = 0; j < m; j++) {
                printf("%d ", students[i].marks[j]);
            }
            printf("(Average: %.2f)\n", students[i].avr);
        }
    }
}

void badGrades(int n, int m) {
    int i, j;
    system("cls");
    printf("Students with grades below 2.50:\n");
    for (i = 0; i < n; i++) {
        if (students[i].avr <= 2.50) {
            printf("%d %s : ", students[i].num, students[i].name);
            for (j = 0; j < m; j++) {
                printf("%d ", students[i].marks[j]);
            }
            printf("(Average: %.2f)\n", students[i].avr);
        }
    }
}