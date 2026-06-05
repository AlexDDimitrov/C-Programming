#include "wor-types.h"

int main(void) {
    File* file = fopen("company.bin", "rb");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    Employee* dir1 = deserialize(file);
    fclose(file);

    printEmp(dir1);

    freeEmp(dir1);
    return 0;
}
