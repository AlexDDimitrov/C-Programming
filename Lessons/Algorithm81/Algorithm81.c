#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void write_on_file(char *filename);
void read_file(char *filename);
void add_on_file(char *filename);
void choose_file(char *filename);

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
        printf("5. Quit\n");

        c = getch();

        if (c == -32 || c == 224)
        {
            c = getch(); 
            if (c == 72) a--; 
            if (c == 80) a++; 
        }

        if (a > 5) a = 1;
        if (a < 1) a = 5;

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
                printf("Quitting...\n");
                m=1;
                break;
            }
            if (a != 5)
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
    fgets(filename, sizeof(filename), stdin);
    if ((p = strchr(filename, '\n'))) *p = '\0';
    printf("File '%s' selected.\n", filename);
}

void write_on_file(char *filename)
{
    if (strlen(filename) == 0) {
        printf("No file selected! Choose a file first.\n");
        return;
    }
    system("cls");
    char line[100];
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error opening file.\n");
    } else {
        while(1){
            fgets(line, sizeof(line), stdin);
            if (strcmp(line, "end\n") == 0) {
                printf("Ending input...\n");
                break;
            }
            fprintf(f, "%s", line);
        }
        fclose(f);
    }
}

void read_file(char *filename)
{
    if (strlen(filename) == 0) {
        printf("No file selected! Choose a file first.\n");
        return;
    }
    char line[100];
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Error opening file '%s' for reading.\n", filename);
    } else {
        printf("Contents of '%s':\n", filename);
        while (!feof(f)) {
            if (fgets(line, sizeof(line), f)) {
                printf("%s", line);
            }
        }
        fclose(f);
    }
}

void add_on_file(char *filename)
{
    if (strlen(filename) == 0) {
        printf("No file selected! Choose a file first.\n");
        return;
    }
    system("cls");
    char line[100];
    FILE *f = fopen(filename, "a");
    if (!f) {
        printf("Error opening file.\n");
    } else {
        while(1){
            fgets(line, sizeof(line), stdin);
            if (strcmp(line, "end\n") == 0) {
                printf("Ending input...\n");
                break;
            }
            fprintf(f, "%s", line);
        }
        fclose(f);
    }
}
