#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//color codes
#define COLOR_BROWN "\033[33m"
#define COLOR_WHITE "\033[97m"
#define COLOR_RESET "\033[0m"

void print_board(char board[8][8]) {
    for (int i = 7; i >= 0; i--) {
        printf("%d  ", i + 1); // Row label (1-8)
        for (int j = 0; j < 8; j++) {
            char piece = board[i][j];
            if (piece) {
                if (piece >= 'a' && piece <= 'z')
                    printf(COLOR_BROWN "%c " COLOR_RESET, toupper(piece));
                else
                    printf(COLOR_WHITE "%c " COLOR_RESET, piece);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("   A B C D E F G H\n"); // Column labels at bottom
}

// Convert chess notation to board indices
int parse_pos(const char *pos, int *row, int *col) {
    if (pos[0] < 'A' || pos[0] > 'H' || pos[1] < '1' || pos[1] > '8') return 0;
    *col = toupper(pos[0]) - 'A';
    *row = pos[1] - '1';
    return 1;
}

int main() {
    char board[8][8] = {0};
    int fr, fc, tr, tc;
    char from[4], to[4];
    // Set up black pieces
    board[0][0] = 'r'; board[0][1] = 'n'; board[0][2] = 'b'; board[0][3] = 'q';
    board[0][4] = 'k'; board[0][5] = 'b'; board[0][6] = 'n'; board[0][7] = 'r';
    for (int i = 0; i < 8; i++) board[1][i] = 'p';

    // Set up white pieces
    board[7][0] = 'R'; board[7][1] = 'N'; board[7][2] = 'B'; board[7][3] = 'Q';
    board[7][4] = 'K'; board[7][5] = 'B'; board[7][6] = 'N'; board[7][7] = 'R';
    for (int i = 0; i < 8; i++) board[6][i] = 'P';

    // Print the chessboard and pieces in beggining positions
    while (1) {
        system("cls");
        print_board(board);

        system("cls");
        print_board(board);

        printf("White move\nMove piece from: ");
        scanf("%3s", from);
        printf("to: ");
        scanf("%3s", to);

        if (!parse_pos(from, &fr, &fc) || !parse_pos(to, &tr, &tc))
            continue;

        // Only allow moving a white pawn ('P')
        if (board[fr][fc] == 'P') {
            // Only allow forward move by 1
            if (tr == fr - 1 && tc == fc && board[tr][tc] == 0) {
            board[tr][tc] = 'P';
            board[fr][fc] = 0;
            }
        }

        system("cls");
        print_board(board);
        printf("Black move\nMove piece from: ");
        scanf("%3s", from);
        printf("to: ");
        scanf("%3s", to);

        if (!parse_pos(from, &fr, &fc) || !parse_pos(to, &tr, &tc))
            continue;

        // Only allow moving a black pawn ('p')
        if (board[fr][fc] == 'p') {
            // Only allow forward move by 1
            if (tr == fr + 1 && tc == fc && board[tr][tc] == 0) {
                board[tr][tc] = 'p';
                board[fr][fc] = 0;
            }
        }
    }
}
