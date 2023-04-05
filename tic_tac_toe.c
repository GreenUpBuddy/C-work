#include <stdio.h>

void draw_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int check_win(char board[3][3], char player) {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char player = 'X';
    int turns = 0;
    int winner = 0;

    while(turns < 9 && winner == 0) {
        printf("Player %c's turn.\n", player);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        row--;
        col--;

        if(board[row][col] == ' ') {
            board[row][col] = player;
            draw_board(board);
            winner = check_win(board, player);
            if(player == 'X') {
                player = 'O';
            } else {
                player = 'X';
            }
            turns++;
        } else {
            printf("That space is already taken. Please try again.\n");
        }
    }

    if(winner) {
        printf("Player %c wins!\n", player);
    } else {
        printf("Tie game.\n");
    }

    return 0;
}
