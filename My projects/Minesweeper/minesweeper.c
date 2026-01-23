#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define COLOR_BROWN "\033[33m"
#define COLOR_WHITE "\033[97m"
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_BLUE "\033[34m"
#define COLOR_LIGHT_BLUE "\033[94m"
#define COLOR_LIGHT_GREEN "\033[92m"
#define COLOR_DARK_BLUE "\033[34m"
#define COLOR_GRAY "\033[90m"
#define COLOR_DARK_RED "\033[91m"
#define COLOR_DARK_GRAY "\033[90m"
#define COLOR_DARK_GREEN "\033[32m"

char board[16][16];
char memory[16][16];

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void initialize_board() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            board[i][j] = '?';
            memory[i][j] = ' ';
        }
    }
}

void print_board() {
    for (int i = 15; i >= 0; i--) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < 16; j++) {
            char display_char = memory[i][j];
            if (display_char == ' ') {
                if ((i + j) % 2 == 0)
                    printf(COLOR_GREEN "- " COLOR_RESET);
                else
                    printf(COLOR_DARK_GREEN "- " COLOR_RESET);
            } else if (board[i][j] == '*') {
                printf(COLOR_RED "%c " COLOR_RESET, display_char);
            } else if (display_char == '0') {
                printf(COLOR_WHITE "%c " COLOR_RESET, display_char);
            } else if (display_char == '1') {
                printf(COLOR_BLUE "%c " COLOR_RESET, display_char);
            } else if (display_char == '2') {
                printf(COLOR_LIGHT_GREEN "%c " COLOR_RESET, display_char);
            } else if (display_char == '3') {
                printf(COLOR_RED "%c " COLOR_RESET, display_char);
            } else if (display_char == '4') {
                printf(COLOR_DARK_BLUE "%c " COLOR_RESET, display_char);
            } else if (display_char == '5') {
                printf(COLOR_DARK_RED "%c " COLOR_RESET, display_char);
            } else if (display_char == '6') {
                printf(COLOR_LIGHT_BLUE "%c " COLOR_RESET, display_char);
            } else if (display_char == '7') {
                printf(COLOR_DARK_GRAY "%c " COLOR_RESET, display_char);
            } else if (display_char == '8') {
                printf(COLOR_GRAY "%c " COLOR_RESET, display_char);
            } else if (display_char == 'F') {
                printf(COLOR_RED "F " COLOR_RESET);
            } else {
                printf("%c ", display_char);
            }
        }
        printf("\n");
    }
    printf("    A B C D E F G H I J K L M N O P\n");
}

char gen_safe_spots[][2] = {
    {-1, -1}, {0, -1}, {1, -1},
    {-1,  0}, {0,  0}, {1,  0},
    {-1,  1}, {0,  1}, {1,  1}
};
void create_mine(int row, int col) {
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
            int safe = 0;
            for (int k = 0; k < 9; k++) {
                if (x == row + gen_safe_spots[k][0] && 
                    y == col + gen_safe_spots[k][1]) {
                    safe = 1;
                    break;
                }
            }
            if (safe)
                board[x][y] = '?';
            else
                board[x][y] = (rand() % 100 < 12) ? '*' : '?';
        }
    }
}

void visualize(int row, int col) {
    if (row < 0 || row >= 16 || col < 0 || col >= 16 || memory[row][col] != ' ')
        return;

    int mine_count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nr = row + i, nc = col + j;
            if (nr >= 0 && nr < 16 && nc >= 0 && nc < 16 && board[nr][nc] == '*')
                mine_count++;
        }
    }

    memory[row][col] = mine_count + '0';

    if (mine_count == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                visualize(row + i, col + j);
            }
        }
    }
}

int moves(int row, int col) {
    if (row < 0 || row >= 16 || col < 0 || col >= 16) return 0;
    if (board[row][col] == '*') {
        printf("Game Over! Hit a mine at %c%d\n", col + 'A', row + 1);
        printf("Press Enter to continue...");
        getchar();
        return 1;
    }
    visualize(row, col);
    return 0;
}

int main() {
    char square[10];
    int row, col;

    srand(time(NULL));
    initialize_board();
    print_board();

    printf("Enter starting square: ");
    scanf("%9s", square);
    clear_input();

    if (strlen(square) < 2 || !isalpha(square[0]) || !isdigit(square[1]) ||
        atoi(&square[1]) < 1 || atoi(&square[1]) > 16) {

        printf("Invalid starting square.\n");
        printf("Press Enter to continue...");
        getchar();
        return 1;
    }

    col = toupper(square[0]) - 'A';
    row = atoi(&square[1]) - 1;

    create_mine(row, col);
    moves(row, col);

    int end = 0;
    while (end == 0) {
        system("cls");
        print_board();
        printf("Choose a move. 1 - flag, 2 - reveal, 3 exit\n");

        int action;
        scanf("%d", &action);
        clear_input();

        if (action == 1) {
            printf("Select a square to flag: ");
            scanf("%9s", square);
            clear_input();

            col = toupper(square[0]) - 'A';
            row = atoi(&square[1]) - 1;

            if (memory[row][col] >= '0' && memory[row][col] <= '8') {
                printf("Cannot flag a revealed square.\n");
                printf("Press Enter to continue...");
                getchar();
                continue;
            }

            if (memory[row][col] == 'F')
                memory[row][col] = ' ';
            else
                memory[row][col] = 'F';

            continue;
        }

        else if (action == 2) {
            printf("Select a square to reveal: ");
            scanf("%9s", square);
            clear_input();

            col = toupper(square[0]) - 'A';
            row = atoi(&square[1]) - 1;

            if (memory[row][col] == 'F') {
                printf("Square is flagged. Unflag it before revealing.\n");
                printf("Press Enter to continue...");
                getchar();
                continue;
            }

            end = moves(row, col);
        }

        else if (action == 3) {
            end = 1;
        }

        else {
            printf("Invalid action. Please choose 1, 2 or 3.\n");
            printf("Press Enter to continue...");
            getchar();
        }
    }

    return 0;
}
