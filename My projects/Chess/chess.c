#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define COLOR_BROWN "\033[33m"
#define COLOR_WHITE "\033[97m"
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"

void print_board(char board[8][8]) {
    for (int i = 7; i >= 0; i--) {
        printf("%d  ", i + 1);
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
    printf("   A B C D E F G H\n");
}

int parse_pos(const char *pos, int *row, int *col) {
    if (pos[0] < 'A' || pos[0] > 'H' || pos[1] < '1' || pos[1] > '8') return 0;
    *col = toupper(pos[0]) - 'A';
    *row = pos[1] - '1';
    return 1;
}

int movingWhite(char board[8][8], int *en_passant_row, int *en_passant_col) {
    int knight_moves[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    char from[4], to[4];
    int fr, fc, tr, tc;

    while (1) {
        printf("White move\nMove piece\nFrom: ");
        scanf("%3s", from);
        printf("To: ");
        scanf("%3s", to);

        if (!parse_pos(from, &fr, &fc) || !parse_pos(to, &tr, &tc)) {
            printf(COLOR_RED "Invalid coordinates.\n" COLOR_RESET);
            continue;
        }

        if (board[fr][fc] == 'P') {
            if (tr == fr - 1 && tc == fc && board[tr][tc] == 0) {
                if (tr == 0) {
                    printf("Promotion! To which piece? ");
                    char promotion;
                    scanf(" %c", &promotion);
                    board[tr][tc] = toupper(promotion);
                } else {
                    board[tr][tc] = 'P';
                }
                board[fr][fc] = 0;
                return 1;
            }
            if (fr == 6 && tr == fr - 2 && tc == fc && board[fr - 1][fc] == 0 && board[tr][tc] == 0) {
                board[tr][tc] = 'P';
                board[fr][fc] = 0;
                *en_passant_row = fr - 1;
                *en_passant_col = fc;
                return 1;
            }
            if (tr == fr - 1 && abs(tc - fc) == 1) {
                if (board[tr][tc] >= 'a' && board[tr][tc] <= 'z') {
                    if (tr == 0) {
                        do{
                            printf("Promotion! To which piece? ");
                            char promotion;
                            scanf(" %c", &promotion);
                            board[tr][tc] = toupper(promotion);
                        } while (board[tr][tc] != 'Q' && board[tr][tc] != 'R' && board[tr][tc] != 'B' && board[tr][tc] != 'N');
                    } else {
                        board[tr][tc] = 'P';
                    }
                    board[fr][fc] = 0;
                    return 1;
                }
                if (tr == *en_passant_row && tc == *en_passant_col && board[fr][tc] == 'p') {
                    board[tr][tc] = 'P';
                    board[fr][fc] = 0;
                    board[fr][tc] = 0;
                    return 1;
                }
            }
        }

        if (board[fr][fc] == 'N') {
            for (int i = 0; i < 8; i++) {
                int dr = knight_moves[i][0];
                int dc = knight_moves[i][1];
                if (fr + dr == tr && fc + dc == tc) {
                    if (board[tr][tc] == 0 || (board[tr][tc] >= 'a' && board[tr][tc] <= 'z')) {
                        board[tr][tc] = 'N';
                        board[fr][fc] = 0;
                        return 1;
                    }
                }
            }
        }

        if (board[fr][fc] == 'R') {
            if (fr == tr)
            {
                int step = (tc > fc) ? 1 : -1;
                int blocked = 0;
                for (int c = fc + step; c != tc; c += step) {
                    if (board[fr][c] != 0) {
                        blocked = 1;
                        break;
                    }
                }
                if (!blocked && (board[tr][tc] == 0 || (board[tr][tc] >= 'a' && board[tr][tc] <= 'z'))) {
                    board[tr][tc] = 'R';
                    board[fr][fc] = 0;
                    return 1;
                }
            } else if (fc == tc) {
                int step = (tr > fr) ? 1 : -1;
                int blocked = 0;
                for (int r = fr + step; r != tr; r += step) {
                    if (board[r][fc] != 0) {
                        blocked = 1;
                        break;
                    }
                }
                if (!blocked && (board[tr][tc] == 0 || (board[tr][tc] >= 'a' && board[tr][tc] <= 'z'))) {
                    board[tr][tc] = 'R';
                    board[fr][fc] = 0;
                    return 1;
                }
            }
        }
        if (board[fr][fc] == 'B') {
            if (abs(tr - fr) == abs(tc - fc)) {
                int row_step = (tr > fr) ? 1 : -1;
                int col_step = (tc > fc) ? 1 : -1;
                int r = fr + row_step, c = fc + col_step;
                int blocked = 0;

                while (r != tr && c != tc) {
                    if (board[r][c] != 0) {
                        blocked = 1;
                        break;
                    }
                    r += row_step;
                    c += col_step;
                }

                if (!blocked && (board[tr][tc] == 0 || (board[tr][tc] >= 'a' && board[tr][tc] <= 'z'))) {
                    board[tr][tc] = 'B';
                    board[fr][fc] = 0;
                    return 1;
                }
            }
        }
    }
}

int movingBlack(char board[8][8], int *en_passant_row, int *en_passant_col) {
    int knight_moves[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    char from[4], to[4];
    int fr, fc, tr, tc;

    while (1) {
        printf(COLOR_BROWN "Black move\nMove piece \nFrom: ");
        scanf("%3s", from);
        printf(COLOR_BROWN "To: ");
        scanf("%3s", to);
        printf(COLOR_RESET);

        if (!parse_pos(from, &fr, &fc) || !parse_pos(to, &tr, &tc)) {
            printf(COLOR_RED "Invalid coordinates.\n" COLOR_RESET);
            continue;
        }

        if (board[fr][fc] == 'p') {
            if (tr == fr + 1 && tc == fc && board[tr][tc] == 0) {
                if (tr == 7) {
                    printf("Promotion! To which piece? ");
                    char promotion;
                    scanf(" %c", &promotion);
                    board[tr][tc] = tolower(promotion);
                } else {
                    board[tr][tc] = 'p';
                }
                board[fr][fc] = 0;
                return 1;
            }
            if (fr == 1 && tr == fr + 2 && tc == fc && board[fr + 1][fc] == 0 && board[tr][tc] == 0) {
                board[tr][tc] = 'p';
                board[fr][fc] = 0;
                *en_passant_row = fr + 1;
                *en_passant_col = fc;
                return 1;
            }
            if (tr == fr + 1 && abs(tc - fc) == 1) {
                if (board[tr][tc] >= 'A' && board[tr][tc] <= 'Z') {
                    if (tr == 7) {
                        do{
                            printf("Promotion! To which piece? ");
                            char promotion;
                            scanf(" %c", &promotion);
                            board[tr][tc] = tolower(promotion);
                        } while (board[tr][tc] != 'q' && board[tr][tc] != 'r' && board[tr][tc] != 'b' && board[tr][tc] != 'n');
                    } else {
                        board[tr][tc] = 'p';
                    }
                    board[fr][fc] = 0;
                    return 1;
                }
                if (tr == *en_passant_row && tc == *en_passant_col && board[fr][tc] == 'P') {
                    board[tr][tc] = 'p';
                    board[fr][fc] = 0;
                    board[fr][tc] = 0;
                    return 1;
                }
            }
        }

        if (board[fr][fc] == 'n') {
            for (int i = 0; i < 8; i++) {
                int dr = knight_moves[i][0];
                int dc = knight_moves[i][1];
                if (fr + dr == tr && fc + dc == tc) {
                    if (board[tr][tc] == 0 || (board[tr][tc] >= 'A' && board[tr][tc] <= 'Z')) {
                        board[tr][tc] = 'n';
                        board[fr][fc] = 0;
                        return 1;
                    }
                }
            }
        }
        if (board[fr][fc] == 'r') {
            if (fr == tr) {
                int step = (tc > fc) ? 1 : -1;
                int blocked = 0;
                for (int c = fc + step; c != tc; c += step) {
                    if (board[fr][c] != 0) {
                        blocked = 1;
                        break;
                    }
                }
                if (!blocked && (board[tr][tc] == 0 || (board[tr][tc] >= 'A' && board[tr][tc] <= 'Z'))) {
                    board[tr][tc] = 'r';
                    board[fr][fc] = 0;
                    return 1;
                }
            } else if (fc == tc) {
                int step = (tr > fr) ? 1 : -1;
                int blocked = 0;
                for (int r = fr + step; r != tr; r += step) {
                    if (board[r][fc] != 0) {
                        blocked = 1;
                        break;
                    }
                }
                if (!blocked && (board[tr][tc] == 0 || (board[tr][tc] >= 'A' && board[tr][tc] <= 'Z'))) {
                    board[tr][tc] = 'r';
                    board[fr][fc] = 0;
                    return 1;
                }
            }
        }

        if (board[fr][fc] == 'b') {
            if (abs(tr - fr) == abs(tc - fc)) {
                int row_step = (tr > fr) ? 1 : -1;
                int col_step = (tc > fc) ? 1 : -1;
                int r = fr + row_step, c = fc + col_step;
                int blocked = 0;

                while (r != tr && c != tc) {
                    if (board[r][c] != 0) {
                        blocked = 1;
                        break;
                    }
                    r += row_step;
                    c += col_step;
                }

                if (!blocked && (board[tr][tc] == 0 || (board[tr][tc] >= 'A' && board[tr][tc] <= 'Z'))) {
                    board[tr][tc] = 'b';
                    board[fr][fc] = 0;
                    return 1;
                }
            }
        }
    }
}

int main() {
    int en_passant_row = -1;
    int en_passant_col = -1;
    char board[8][8] = {0};

    // Set up black pieces
    board[0][0] = 'r'; board[0][1] = 'n'; board[0][2] = 'b'; board[0][3] = 'q';
    board[0][4] = 'k'; board[0][5] = 'b'; board[0][6] = 'n'; board[0][7] = 'r';
    for (int i = 0; i < 8; i++) board[1][i] = 'p';

    // Set up white pieces
    board[7][0] = 'R'; board[7][1] = 'N'; board[7][2] = 'B'; board[7][3] = 'Q';
    board[7][4] = 'K'; board[7][5] = 'B'; board[7][6] = 'N'; board[7][7] = 'R';
    for (int i = 0; i < 8; i++) board[6][i] = 'P';

    // Main game loop
    while (1) {
        system("cls");
        print_board(board);
        movingWhite(board, &en_passant_row, &en_passant_col);

        system("cls");
        print_board(board);
        movingBlack(board, &en_passant_row, &en_passant_col);
    }
}
