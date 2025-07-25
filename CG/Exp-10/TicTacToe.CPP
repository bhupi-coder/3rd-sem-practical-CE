#include <stdio.h>  // Use stdio.h for Turbo C++
#include <conio.h>  // Use conio.h for getch()

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

// Function prototypes
void displayBoard();
int checkWin();
int checkDraw();
void makeMove(char player);

int main() {
    char player = 'X';
    int gameWon = 0, draw = 0;

    // Game loop
    while (!gameWon && !draw) {
        displayBoard();
        makeMove(player);

        gameWon = checkWin();
        draw = checkDraw();

        if (!gameWon && !draw) {
            // Switch player
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    displayBoard();

    if (gameWon) {
        printf("Player %c wins!\n", player);
    } else {
        printf("It's a draw!\n");
    }

    getch();  // To pause the output screen
    return 0;
}

// Function to display the current board
void displayBoard() {
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

// Function to check if any player has won
int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

// Function to check if the game is a draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // There's still a move left
            }
        }
    }
    return 1; // No moves left
}

// Function to make a move for the current player
void makeMove(char player) {
    int choice;
    printf("Player %c, enter your move (1-9): ", player);
    scanf("%d", &choice);

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // Check if the chosen spot is valid
    if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
    } else {
        printf("Invalid move! Try again.\n");
        makeMove(player);
    }
}
