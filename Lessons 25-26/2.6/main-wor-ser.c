#include "wor-types.h"

int main(void) {
    Employee* w1 = create("Worker 1.1.1", 0);
    Employee* w2 = create("Worker 1.1.2", 0);
    Employee* w3 = create("Worker 1.1.3", 0);

    Employee* w4 = create("Worker 1.2.1", 0);
    Employee* w5 = create("Worker 1.2.2", 0);
    Employee* w6 = create("Worker 1.2.3", 0);

    Employee* m1 = create("Manager 1.1", 3);
    m1->subs[0] = w1;
    m1->subs[1] = w2;
    m1->subs[2] = w3;

    Employee* m2 = create("Manager 1.2", 3);
    m2->subs[0] = w4;
    m2->subs[1] = w5;
    m2->subs[2] = w6;

    Employee* director1 = create("Director 1", 2);
    director1->subs[0] = m1;
    director1->subs[1] = m2;

    File* file = fopen("company.bin", "wb");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    serialize(director1, file);
    fclose(file);

    freeEmp(director1);
    return 0;
}
