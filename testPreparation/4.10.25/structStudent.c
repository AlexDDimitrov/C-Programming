#include <stdio.h>

struct student
{
    char name[20];
    int num;
    float avr;
};

struct student Student1;
int main() {
    printf("Enter name of student: ");
    fgets(Student1.name, 100, stdin);
    for (int i = 0; Student1.name[i] != '\0'; i++)
    {
        if(Student1.name[i] == '\n') Student1.name[i] = '\0';
    }

    do {
        printf("Enter number of student: ");
        scanf("%d", &Student1.num);
    } while(Student1.num<0);

    do {
        printf("Enter avr of student: ");
        scanf("%f", &Student1.avr);
    } while(Student1.avr<2 || Student1.avr>6);


    printf("Name: %s\n", Student1.name);
    printf("Num: %d\n", Student1.num);
    printf("Name: %.2f\n", Student1.avr);

    return 0;
}
