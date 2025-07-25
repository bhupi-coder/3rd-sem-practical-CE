#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

// Function prototypes
void displayBoard();
bool checkWin();
bool checkDraw();
void makeMove(char player);

int main() {
    char player = 'X';
    bool gameWon = false, draw = false;

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
        cout << "Player " << player << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

// Function to display the current board
void displayBoard() {
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "     |     |     " << endl;
}

// Function to check if any player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // There's still a move left
            }
        }
    }
    return true; // No moves left
}

// Function to make a move for the current player
void makeMove(char player) {
    int choice;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // Check if the chosen spot is valid
    if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
    } else {
        cout << "Invalid move! Try again." << endl;
        makeMove(player);
    }
}

