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
    int m;
    char *p;
    printf("Enter student name: ");
    fgets(st.name, sizeof(st.name), stdin);
    if(p = strchr(st.name, '\n')) *p = '\0'; 
    
    do{
        printf("Enter number of subjects (<=20): ");
        scanf("%d", &m);
    } while (m < 1 || m > 20);
    st.avr = 0;
    for(int i = 0; i < m; i++) {
        do{
            printf("Enter mark %d: ", i + 1);
            scanf("%d", &st.marks[i]);
        } while (st.marks[i] < 0 || st.marks[i] > 6);
        st.avr += st.marks[i];
    }

    st.avr /= m;

    printf("Name: %s\n", st.name);
    printf("Marks: ");
    for(int i = 0; i < m; i++) {
        printf("%d, ", st.marks[i]);
    }
    printf("\n");
    printf("Average mark: %.2f\n", st.avr);
}
