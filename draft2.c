#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void clearScreen();
void printMenu();
void coinTossGame();
void numberGuessingGame();
void rockPaperScissorsGame();
void ticTacToeGame();
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
int checkWin(char board[3][3], char symbol);
int checkDraw(char board[3][3]);
void getMove(char board[3][3], int player);
void print_choice(int choice);

int main() {
    int choice;
    srand(time(NULL)); 

    while (1) {
        clearScreen();
        printMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearScreen();
                coinTossGame();
                break;
            case 2:
                clearScreen();
                numberGuessingGame();
                break;
            case 3:
                clearScreen();
                rockPaperScissorsGame();
                break;
            case 4:
                clearScreen();
                ticTacToeGame();
                break;
            case 5:
                clearScreen();
                printf("Thank you for playing GameZone! Goodbye!\n");
                exit(0);
            default:
                clearScreen();
                printf("Invalid choice! Please select a valid option.\n");
                printf("Press Enter to continue...");
                getchar(); 
                getchar(); 
        }
    }
    return 0;
}


void clearScreen() {
    system("cls"); 
}


void printMenu() {
    printf("===== Welcome to GameZone =====\n");
    printf("1. Coin Toss Game\n");
    printf("2. Number Guessing Game\n");
    printf("3. Rock Paper Scissors\n");
    printf("4. Tic-Tac-Toe\n");
    printf("5. Exit\n");
    printf("=============================\n");
}

// ---------Coin Toss Game-----------
void coinTossGame() {
    int user_choice;
    int coin;
    char play_again;

    do {
        printf("\n--- Coin Toss Game ---\n");
        printf("Choose:\n");
        printf("1. Heads\n2. Tails\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &user_choice);

        if (user_choice != 1 && user_choice != 2) {
            printf("Invalid choice. Please select 1 or 2.\n");
            continue;
        }

        coin = (rand() % 2) + 1; 

        if (coin == 1) {
            printf("The coin landed on: Heads\n");
        } else {
            printf("The coin landed on: Tails\n");
        }

        if (user_choice == coin) {
            printf("You win!\n");
        } else {
            printf("You lose.\n");
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing!\n");
    printf("Press Enter to return to the menu...");
    getchar(); 
    getchar(); 
}

// --------------Number Guessing Game---------------
void numberGuessingGame() {
    int randomNumber, guess, attempts = 0;
    int difference;

    randomNumber = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("Try to guess a number between 1 and 100!\n\n");
    printf("Explanation:\n");
    printf("- If you are exactly 1 number away: 'You are very very very close!'\n");
    printf("- If you are within 4 numbers: 'You are very close!'\n");
    printf("- Otherwise: 'Too high' or 'Too low'\n");
    printf("Tip: sHHHH! Try Using Binary Search...;)\n\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Invalid guess! Enter a number between 1 and 100.\n");
            continue;
        }

        attempts++;

        if (guess == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }

        difference = guess - randomNumber;
        if (difference == 1 || difference == -1) {
            printf("You are very very very close! Try again.\n");
        } else if (difference <= 4 && difference >= -4) {
            printf("You are very close! Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Too low! Try again.\n");
        }
    }

    printf("Press Enter to return to the menu...");
    getchar(); 
    getchar(); 
}

// ----------------------Rock Paper Scissors Game------------------
void rockPaperScissorsGame() {
    int player_choice, computer_choice;
    int player_score = 0, computer_score = 0;
    char play_again;

    do {
        printf("\n--- Rock Paper Scissors ---\n");
        printf("Choose an option:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &player_choice);

        if (player_choice < 1 || player_choice > 3) {
            printf("Invalid choice. Please select 1, 2, or 3.\n");
            continue;
        }

        computer_choice = (rand() % 3) + 1;

        printf("You chose: ");
        print_choice(player_choice);
        printf("\nComputer chose: ");
        print_choice(computer_choice);
        printf("\n");

        if (player_choice == computer_choice) {
            printf("It's a draw!\n");
        } else {
            if (player_choice == 1 && computer_choice == 3) {
                printf("You win! Rock beats Scissors.\n");
                player_score++;
            } else if (player_choice == 2 && computer_choice == 1) {
                printf("You win! Paper beats Rock.\n");
                player_score++;
            } else if (player_choice == 3 && computer_choice == 2) {
                printf("You win! Scissors beats Paper.\n");
                player_score++;
            } else if (computer_choice == 1 && player_choice == 3) {
                printf("Computer wins! Rock beats Scissors.\n");
                computer_score++;
            } else if (computer_choice == 2 && player_choice == 1) {
                printf("Computer wins! Paper beats Rock.\n");
                computer_score++;
            } else if (computer_choice == 3 && player_choice == 2) {
                printf("Computer wins! Scissors beats Paper.\n");
                computer_score++;
            }
        }

        printf("Score - You: %d | Computer: %d\n", player_score, computer_score);
        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing!\n");
    printf("Press Enter to return to the menu...");
    getchar(); 
    getchar(); 
}


void print_choice(int choice) {
    if (choice == 1) {
        printf("Rock");
    } else if (choice == 2) {
        printf("Paper");
    } else if (choice == 3) {
        printf("Scissors");
    }
}

// ------------------Tic-Tac-Toe Game---------------
void ticTacToeGame() {
    char board[3][3];
    int player = 1;
    int gameOver = 0;

    initializeBoard(board);

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1: X  |  Player 2: O\n");
    printf("Enter your move as row and column (e.g., 2 3 means row 2, column 3).\n");

    while (gameOver==0) {
        displayBoard(board);
        getMove(board, player);

        char currentSymbol;
        if (player == 1) {
            currentSymbol = 'X';
        } else {
            currentSymbol = 'O';
        }

        if (checkWin(board, currentSymbol)) {
            displayBoard(board);
            printf("Player %d wins!\n", player);
            gameOver = 1;
        } else if (checkDraw(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            gameOver = 1;
        } else {
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        }
    }

    printf("Press Enter to return to the menu...");
    getchar(); 
    getchar(); 
}


void initializeBoard(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[3][3]) {
    int i;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("\n---+---+---\n");
        }
    }
    printf("\n\n");
}

int checkWin(char board[3][3], char symbol) {
    int i;

  
    for (i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

 
    for (i = 0; i < 3; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }


    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }

 
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }

    return 0;
}

int checkDraw(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void getMove(char board[3][3], int player) {
    int row, col;
    char symbol;
    if (player == 1) {
        symbol = 'X';
    } else {
        symbol = 'O';
    }

    while (1) {
        printf("Player %d (%c), enter your move (row [1-3] column [1-3]): ", player, symbol);
        scanf("%d %d", &row, &col);

        row = row - 1;
        col = col - 1;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = symbol;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}