#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>



void write_on_file(char *filename);
void read_file(char *filename);
void add_on_file(char *filename);
void choose_file(char *filename);
void delete_file(char *filename);

typedef struct {
    int num;
    char name[80];
    int marks[20];
    float average;
} Student;
Student s;

int main()
{
    int a = 1;
    int m;
    char c;
    int nfile;
    char *p;
    char filename[20] = "";
    char line[100];
    m=0;
    do
    {
        system("cls");
        printf(" Menu\n");
        if (a == 1) printf(">");
        else printf(" ");
        printf("1. Choose file\n");
        if (a == 2) printf(">");
        else printf(" ");
        printf("2. Write on file\n");
        if (a == 3) printf(">");
        else printf(" ");
        printf("3. Read file\n");
        if (a == 4) printf(">");
        else printf(" ");
        printf("4. Add on file\n");
        if (a == 5) printf(">");
        else printf(" ");
        printf("5. Delete file\n");
        if (a == 6) printf(">");
        else printf(" ");
        printf("6. Quit\n");

        c = getch();

        if (c == -32 || c == 224)
        {
            c = getch(); 
            if (c == 72) a--; 
            if (c == 80) a++; 
        }

        if (a > 6) a = 1;
        if (a < 1) a = 6;

        if (c == '\r')
        {
            switch (a)
            {
            case 1:
                system("cls");
                choose_file(filename);
                break;
            case 2:
                system("cls");
                write_on_file(filename);
                break;
            case 3:
                system("cls");
                read_file(filename);
                break;
            case 4:
                system("cls");
                add_on_file(filename);
                break;
            case 5:
                system("cls");
                delete_file(filename);
                break;
            case 6:
                printf("Quitting...\n");
                m=1;
                break;
            }
            if (a != 6)
            {
                printf("Press any key to continue...\n");
                getch();
            }
        }

    } while (m==0);

    return 0;
}

void choose_file(char *filename)
{
    char *p;
    printf("Enter filename: ");
    fgets(filename, 20, stdin);
    if ((p = strchr(filename, '\n'))) *p = '\0';
    printf("File '%s' selected.\n", filename);
}

void write_on_file(char *filename)
{
    FILE *f;
    Student s;
    char *p;
    char yes='Y';
    int i = 0, j;
    if (strlen(filename) == 0) {
        printf("No file selected! Choose a file first.\n");
        return;
    }

    if((f = fopen(filename, "r")))
    {
        printf("File exists! Overwrite Y/N? ");
        scanf(" %c", &yes); 
        getchar();
        fclose(f);
    }
    if(yes != 'Y' && yes != 'y') return;

    if((f = fopen(filename, "w")))
    {
        while(1)
        {
            printf("Num: ");
            scanf("%d", &s.num); getchar();
            if(s.num == 0) break;
            i++;
            printf("Name: ");
            fgets(s.name, sizeof(s.name), stdin);
            if(p = strchr(s.name, '\n')) *p = '\0';

            j = 0; s.average = 0;
            while(1)
            {
                do {
                    printf("Mark %d Student %d (2-6, 0 to finish): ", j + 1, i);
                    scanf("%d", &s.marks[j]);
                } while ((s.marks[j] < 2 || s.marks[j] > 6) && s.marks[j] != 0);
                
                if(s.marks[j] == 0) break;
                s.average += s.marks[j];
                j++;
            }
            if(j > 0) s.average = s.average / j;
            fwrite(&s, sizeof(s), 1, f);
        }
        fclose(f);
        printf("Data successfully written to '%s'.\n", filename);
    }
    else printf("ERROR OPEN FILE FOR WRITING!");
}

void read_file(char *filename)
{
    FILE *f;
    Student s;
    int i;
    if (strlen(filename) == 0) {
        printf("No file selected! Choose a file first.\n");
        return;
    }
    if((f = fopen(filename, "r")))
    {
        printf("Contents of '%s':\n", filename);
        while(fread(&s, sizeof(s), 1, f))
        {
            printf("%-3d %-20s", s.num, s.name);
            for(i = 0; s.marks[i]; i++) printf("%-3d", s.marks[i]);
            printf("%-6.2f\n", s.average);
        }
        fclose(f);
    }
    else printf("ERROR OPEN FILE FOR READING!");
}

void add_on_file(char *filename)
{
    FILE *f;
    Student s;
    char *p;
    int i = 0, j;
    if (strlen(filename) == 0) {
        printf("No file selected! Choose a file first.\n");
        return;
    }
    if((f = fopen(filename, "a")))
    {
        while(1)
        {
            printf("Num: ");
            scanf("%d", &s.num); 
            getchar();
            if(s.num == 0) break;
            i++;
            printf("Name: ");
            fgets(s.name, sizeof(s.name), stdin);
            if(p = strchr(s.name, '\n')) *p = '\0';

            j = 0; s.average = 0;
            while(1)
            {
                printf("Mark %d Student %d: ", j + 1, i);
                scanf("%d", &s.marks[j]);
                if(s.marks[j] == 0) break;
                s.average += s.marks[j];
                j++;
            }
            if(j > 0) s.average = s.average / j;
            fwrite(&s, sizeof(s), 1, f);
        }
        fclose(f);
        printf("Records successfully added to '%s'.\n", filename);
    }
    else printf("ERROR OPEN FILE FOR APPENDING!");
}

void delete_file(char *filename)
{
    FILE *f;
    Student students[100];
    int count = 0, i, del_num, found = 0;

    if (strlen(filename) == 0) {
        printf("No file selected! Choose a file first.\n");
        return;
    }

    f = fopen(filename, "r");
    if (!f) {
        printf("ERROR OPEN FILE FOR READING!\n");
        return;
    }
    else {
        while (fread(&s, sizeof(s), 1, f)) {
            count++;
            students[count - 1] = s;
        }
        fclose(f);

        if (count == 0) {
            printf("File is empty.\n");
            return;
        }

        printf("Enter student number to delete: ");
        scanf("%d", &del_num);
        getchar();

        for (i = 0; i < count; i++) {
            if (students[i].num == del_num) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Student number %d not found.\n", del_num);
            return;
        }

        for (; i < count - 1; i++) {
            students[i] = students[i + 1];
        }
        count--;

        f = fopen(filename, "w");
        if (!f) {
            printf("ERROR OPEN FILE FOR WRITING!\n");
            return;
        }
        for (i = 0; i < count; i++) {
            fwrite(&students[i], sizeof(Student), 1, f);
        }
        fclose(f);

        printf("Student number %d deleted successfully.\n", del_num);
    }
}