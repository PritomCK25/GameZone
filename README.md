# GameZone
A Simple Terminal Based GameZone Developed With C by Pritom_Chakraborty
GameZone - Terminal-Based C Game Collection
Overview
GameZone is a terminal-based game collection written in C, offering four simple games: Coin Toss, Number Guessing, Rock Paper Scissors, and Tic-Tac-Toe. The program features a menu-driven interface where users can select a game to play using a switch-case structure. Each game is designed with basic logic (using if-else and for loops) for clarity and ease of understanding. After playing a game, users can return to the main menu to choose another game or exit.
Features

Menu-Driven Interface: Choose from four games or exit using a simple numbered menu.
Games Included:
Coin Toss: Guess Heads or Tails and see if you win.
Number Guessing: Guess a number between 1 and 100 with hints about closeness.
Rock Paper Scissors: Play against the computer with score tracking.
Tic-Tac-Toe: Two-player game with a 3x3 grid.


Simple Logic: Uses basic if-else statements and for loops for easy comprehension.
Cross-Platform: Works on Unix-like systems and Windows (with minor adjustment).

Requirements

C Compiler: GCC or any standard C compiler (e.g., gcc).
Operating System: Unix-like (Linux, macOS) or Windows.
Standard Libraries: Uses stdio.h, stdlib.h, and time.h (included in standard C).

Compilation and Running

Save the Code:
Save the main program as gamezone.c.


Compile:
Open a terminal in the directory containing gamezone.c.
Run:gcc gamezone.c -o gamezone

(No additional libraries like -lm are required.)


Run:
On Unix-like systems (Linux, macOS):./gamezone


On Windows:gamezone.exe




Windows Note:
The program uses system("clear") to clear the terminal. For Windows, edit gamezone.c and replace system("clear") with system("cls") in the clearScreen function before compiling.



How to Play

Start the Program:
Run the compiled program to see the main menu:===== Welcome to GameZone =====
1. Coin Toss Game
2. Number Guessing Game
3. Rock Paper Scissors
4. Tic-Tac-Toe
5. Exit
=============================




Select a Game:
Enter a number (1-5) to choose a game or exit.
If an invalid choice is entered, the program prompts you to try again.


Playing Each Game:
Coin Toss Game:
Choose 1 (Heads) or 2 (Tails).
The program flips a coin and tells you if you win or lose.
Choose to play again (y/n) or return to the menu.


Number Guessing Game:
Guess a number between 1 and 100.
Get hints (e.g., "Too high," "Very close," or "Very very very close").
Continue until you guess correctly, then return to the menu.


Rock Paper Scissors:
Choose 1 (Rock), 2 (Paper), or 3 (Scissors).
Play against the computer, see the result, and track scores.
Choose to play again (y/n) or return to the menu.


Tic-Tac-Toe:
Two players take turns (Player 1: X, Player 2: O).
Enter row and column (1-3) to place your symbol.
Play until someone wins or the game is a draw, then return to the menu.




Return to Menu:
After each game (or choosing not to play again), press Enter to return to the main menu.



Code Structure

Main Program:
main(): Contains the menu loop and switch-case to select games.
clearScreen(): Clears the terminal for a clean display.
printMenu(): Displays the game selection menu.


Game Functions:
coinTossGame(): Handles the Coin Toss game logic.
numberGuessingGame(): Handles the Number Guessing game logic.
rockPaperScissorsGame(): Handles the Rock Paper Scissors game logic.
ticTacToeGame(): Handles the Tic-Tac-Toe game logic with helper functions:
initializeBoard(): Sets up an empty 3x3 board.
displayBoard(): Prints the Tic-Tac-Toe board.
checkWin(): Checks for a winning condition.
checkDraw(): Checks for a draw.
getMove(): Gets and validates player moves.
print_choice(): Prints

//this description was built with AI





