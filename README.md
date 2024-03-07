# Knight Escape: A Chess Puzzle Game

## This GitHub repository hosts a C++ program called "Knight Escape," a puzzle game based on chess mechanics where the player needs to move a white knight to a specific position on the board. Utilizing standard chess knight moves, players must navigate the knight in L-shaped patterns to reach the target square while avoiding black knights and optimizing the number of moves to maintain a high score.

### Game Objective
 * Your goal is to move the white knight to the empty square in the upper-right corner of the board (position 5).
 * The knight should move according to standard chess rules, specifically in an L-shape: two squares in one direction followed by one square perpendicular to the first direction,    or vice versa.
 * The board is populated with black knights, which are static obstacles.
 * Each valid move decreases your score by 5 points, and each invalid move decreases it by 10 points. Start with a score of 500 and aim to keep it as high as possible.

### Features
 * Chess-based Puzzle: Utilize your understanding of knight movements in chess to solve the puzzle.
 * Interactive Gameplay: Make moves, reset the board, or exit the game through user inputs.
 * Score Tracking: Keep an eye on your score, trying to solve the puzzle with minimal valid moves to maintain a high score.
 * Game Board Display: Visual representation of the game board with the positions of all pieces clearly displayed.

### How to Play
1. Start the Game: Run the program to see the initial board setup with the white knight and black knights in their starting positions.
2. Make a Move: Input 'M' followed by the positions you're moving from and to (e.g., 21 8 to move the knight from position 21 to 8).
3. Invalid Moves: If a move is invalid (wrong direction, out of bounds, or onto a black knight), the game will prompt you to try again.
4. Reset the Board: At any point, you can reset the board to its initial state by inputting 'R'.
5. Exit the Game: Enter 'X' to stop playing and exit the game.

