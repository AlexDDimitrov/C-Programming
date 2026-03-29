#include <stdio.h>

typedef struct Node {
    char firstname[30];
    struct Node* father;
    struct Node* mother;
    struct Node* marriedTo;
} Node;

void printPerson(Node* p) {
    if (p == NULL) return;

    printf("\nPerson Me\n");
    printf("Name: %s\n", p->firstname);

    if (p->father != NULL) {
        printf("Father: %s\n", p->father->firstname);
    } else {
        printf("Father: Unknown\n");
    }

    if (p->mother != NULL) {
        printf("Mother: %s\n", p->mother->firstname);
    } else {
        printf("Mother: Unknown\n");
    }

    if (p->marriedTo != NULL) {
        printf("Married to: %s\n", p->marriedTo->firstname);
    } else {
        printf("Married to: Not married\n");
    }
}

int main() {
    Node grandfather1 = {"Todor", NULL, NULL, NULL};
    Node grandmother1 = {"Angelina", NULL, NULL, NULL};

    Node grandfather2 = {"Pepi", NULL, NULL, NULL};
    Node grandmother2 = {"Elena", NULL, NULL, NULL};

    Node mom = {"Lidiya", &grandfather1, &grandmother1, NULL};
    Node dad = {"Dimitar", &grandfather2, &grandmother2, NULL};

    dad.marriedTo = &mom;
    mom.marriedTo = &dad;

    Node me = {"Aleksander", &dad, &mom, NULL};

    printPerson(&grandfather1);
    printPerson(&grandmother1);
    printPerson(&grandfather2);
    printPerson(&grandmother2);
    printPerson(&dad);
    printPerson(&mom);
    printPerson(&me);

    return 0;
}
