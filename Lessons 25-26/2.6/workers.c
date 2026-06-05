/*Да се направи програма, която да сериализира и десериализира йерархия от работници във фирма, в бинарен файл. За целта:
Да се създаде структура служител (Employee), който има име (до 100 символа), брой подчинени служители и списък с подчинени служители. Списъкът от подчинени служители трябва да се пази в масив от указатели (тоест в двоен указател) от тип служител, за да може да добавяме други служители като подчинени на текущия. Ако служителят няма подчинени работници, този двоен указател трябва да сочи към NULL. (Насока: създайте първо работниците, после мениджърите и после директора, за да можете да ги добавите. Използвайте динамично заделяне на памет, за да създадете списъците от подчинени).
Да се създаде програма, която създава йерархия от служители (примерно един директор, който има двама мениджъри, всеки мениджър има по трима подчинени) и която сериализира тази йерархия в бинарен файл.
Да се направи втора програма, която да чете данните от бинарния файл и да ги десериализира обратно в йерархия и след това да принтира на екрана данните от йерархията подравнени. Например:
   Име на директор
       Име на мениджър 1
           Име на работник 1 
           Име на работник 2
           Име на работник 3
       Име на мениджър 2
           Име на работник 4
           Име на работник 5
           Име на работник 6*/

#include "wor-types.h"

static void check_alloc(void* ptr) {
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

Employee* create(const char* name, int subNum) {
    Employee * temp = malloc(sizeof(Employee));
    
    check_alloc(temp);

    strcpy(temp->name, name);
    temp->subC = subNum;
    if (subNum > 0) {
        temp->subs = malloc(subNum * sizeof(Employee*));
        check_alloc(temp->subs);
    } else {
        temp->subs = NULL;
    }
    return temp;
}

void freeEmp(Employee* emp) {
    if (emp) {
        for (int i = 0; i < emp->subC; i++) {
            freeEmp(emp->subs[i]);
        }

        free(emp->subs);
        free(emp);
    }
}

void serialize(Employee* emp, FILE* file) {
    if (emp != NULL) {
        fwrite(emp->name, sizeof(char), MAX_NAME_LENGTH, file);
        fwrite(&emp->subC, sizeof(int), 1, file);

        for (int i = 0; i < emp->subC; i++) {
            serialize(emp->subs[i], file);
        }
    }
}

Employee* deserialize(FILE* file) {
    Employee* emp = malloc(sizeof(Employee));

    check_alloc(emp);

    fread(emp->name, sizeof(char), MAX_NAME_LENGTH, file);
    fread(&emp->subC, sizeof(int), 1, file);

    if (emp->subC > 0) {
        emp->subs = malloc(sizeof(Employee*) * emp->subC);
        check_alloc(emp->subs);
        for (int i = 0; i < emp->subC; i++) {
            emp->subs[i] = deserialize(file);
        }
    } else {
        emp->subs = NULL;
    }

    return emp;
}

void printEmp(Employee* emp) {
    printf("%s\n", emp->name);

    for (int i = 0; i < emp->subC; i++) {
        printEmp(emp->subs[i]);
    }
}