#include <stdio.h>
#include <stdlib.h>
#include <Time.h>
#include <ctype.h>

char board[16][16];
char memory[16][16];

void initialize_board() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            board[i][j] = '0';
        }
    }
}

void print_board() {
    for (int i = 15; i >= 0; i--) {
        if (i + 1 < 10)
            printf(" %d  ", i + 1);
        else {
            printf("%d  ", i + 1);
        }
        for (int j = 0; j < 16; j++) {
            char piece = memory[i][j];
            printf("%c ", piece);
        }
        printf("\n");
    }
    printf("    A B C D E F G H I J K L M N O P\n");
}

void create_mine(int row, int col) {
    srand(time(NULL));
    for (int x = 0; x < 16; x++)
        for (int y = 0; y < 16; y++) {
            int r = rand() % 100;
            if (x == row && y == col) {
                board[x][y] = ' '; // Ensure the selected square is not a mine
                continue;
            }
            if (r < 12) {
                board[x][y] = '*';
            } else {
                board[x][y] = '?';
            }
        }
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++) {
            memory[i][j] = '?';
        }
}

void visualize(int row, int col) {
    int mine_count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int new_row = row + i;
            int new_col = col + j;
            if (new_row >= 0 && new_row < 16 && new_col >= 0 && new_col < 16) {
                if (board[new_row][new_col] == '*') {
                    mine_count++;
                }
            }
        }
    }
    board[row][col] = mine_count + '0';
    memory[row][col] = board[row][col];
    if (mine_count == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int new_row = row + i;
                int new_col = col + j;
                if (new_row >= 0 && new_row < 16 && new_col >= 0 && new_col < 16) {
                    if (memory[new_row][new_col] == '?') {
                        visualize(new_row, new_col);
                    }
                }
            }
        }
    }
}

int moves(int row, int col) {
    switch (board[row][col])
    {
    case '*':
        printf("Game Over!\n");
        return 1;
    case '?':
        memory[row][col] = board[row][col];
        visualize(row, col);
        break;
    default:
        memory[row][col] = board[row][col];
        break;
    }
    return 0;
}

int main() {
    initialize_board();
    print_board();
    printf("Select a square to reveal: ");
    char square[4];
    scanf("%s", square);
    int row = square[1] - '1';
    int col = square[0] - 'A';
    create_mine(row, col);
    print_board();
    int end = 1;
    while (end == 0) {
        system("cls");
        print_board();
        printf("Select a square to reveal: ");
        scanf("%s", square);
        row = square[1] - '1';
        col = square[0] - 'A';
        end = moves(row, col);
    }
    return 0;
}