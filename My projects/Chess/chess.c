#include <stdio.h>
#include <ctype.h> // For toupper

//color codes
#define COLOR_BROWN "\033[33m"
#define COLOR_WHITE "\033[97m"
#define COLOR_RESET "\033[0m"

int main() {
    char board[8][8] = {0};

    // Set up black pieces
    board[0][0] = 'r'; board[0][1] = 'n'; board[0][2] = 'b'; board[0][3] = 'q';
    board[0][4] = 'k'; board[0][5] = 'b'; board[0][6] = 'n'; board[0][7] = 'r';
    for (int i = 0; i < 8; i++) board[1][i] = 'p';

    // Set up white pieces
    board[7][0] = 'R'; board[7][1] = 'N'; board[7][2] = 'B'; board[7][3] = 'Q';
    board[7][4] = 'K'; board[7][5] = 'B'; board[7][6] = 'N'; board[7][7] = 'R';
    for (int i = 0; i < 8; i++) board[6][i] = 'P';

    // Print the chessboard and pieces in beggining positions
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            char piece = board[i][j];
            if (piece) {
                if (piece >= 'a' && piece <= 'z') {
                    printf(COLOR_BROWN "%c " COLOR_RESET, toupper(piece));
                } else {
                    printf(COLOR_WHITE "%c " COLOR_RESET, piece);
                }
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    return 0;
}
