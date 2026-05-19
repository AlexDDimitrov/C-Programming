#include<stdio.h>
//Hanoi//
int count = 0;
void solveHanoi(int n, char firstColumn, char secondColumn, char thirdColumn);

int main() {
    int n;
    do {
        printf("Enter n = ");
        scanf("%d", &n);
    } while(n < 1);
    
    printf("The fastest solution is:\n");
    solveHanoi(n, 'A', 'B', 'C');
    printf("Total moves for %d disks %d\n", n, count);
    return 0;
}

void solveHanoi(int n, char firstColumn, char secondColumn, char thirdColumn) 
{
    if (n == 1) 
    {
        printf("Move disk %d from %c to %c\n", n, firstColumn, thirdColumn);
        count ++;
    }
    else
    {
        count++;
        solveHanoi(n - 1, firstColumn, thirdColumn, secondColumn);
        printf("Move disk %d from %c to %c\n", n, firstColumn, thirdColumn);
        solveHanoi(n - 1 , secondColumn, firstColumn, thirdColumn);
    }
}