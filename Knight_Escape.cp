/*--------------------------------------------
   Program 2: Knight Escape
   The objective of this game is to get the white knight to the empty
    square in the upper right-hand corner of the board.
    
    The knight can only move in the way that it does during a traditional
    chess game. This means that a knight can only move in a valid L-shape
    (two squares in a horizontal direction, then one in a vertical direction OR
    two squares in a vertical direction, then one in a horizontal direction).
               
   Course: CS 141, Spring 2022
   System: XCode on Mac OS Monterey
   Author: Ceasar Attar
    
 ---------------------------------------------*/

#include <iostream>        // for input and output
#include <cctype>           // for toupper()
#include <cmath> //for abs()
using namespace std;

// Global variables for the pieces are allowed for this program,
// but will generally not be allowed in the future.
// You will likely want to declare global variables at least for the 25 board positions.
// ...

// Characters of the pieces to be used on the board
// Note that these are global constants, so their values cannot be changed.
const string WhiteKnight = "\u2658";        // White knight character
const string BlackKnight = "\u265E";        // Black knight character
const string BlankPosition = " ";           // Blank position character
int whiteKnightPosition = 21;               // sets the white knight's position to the initial value and then shows the current position of the                                             //white knight as the user inputs moves
int blankPos = 5;                           // variable used to track the moveFrom variable
int moveNumber = 1;                         // initializes the int variable moveNumber which tracks the number of moves
int score = 500;                            // initializes the int variable score which tracks the score
char menuOption;                            // initializes the char variable menuOption which asks for the user input for the menu options
int moveFrom;                               // initializes the int variable moveFrom which tracks the knight position you want to move from
int moveTo;                                 // initializes the int variable moveFrom which tracks the knight position you want to move to

string p1 = BlackKnight;                    // initializes p1 as a black knight
string p2 = BlackKnight;                    // initializes p2 as a black knight
string p3 = BlackKnight;                    // initializes p3 as a black knight
string p4 = BlackKnight;                    // initializes p4 as a black knight
string p5 = BlankPosition;                  // initializes p5 as a blank position
string p6 = BlackKnight;                    // initializes p6 as a black knight
string p7 = BlackKnight;                    // initializes p7 as a black knight
string p8 = BlackKnight;                    // initializes p8 as a black knight
string p9 = BlackKnight;                    // initializes p9 as a black knight
string p10 = BlackKnight;                   // initializes p10 as a black knight
string p11 = BlackKnight;                   // initializes p11 as a black knight
string p12 = BlackKnight;                   // initializes p12 as a black knight
string p13 = BlackKnight;                   // initializes p13 as a black knight
string p14 = BlackKnight;                   // initializes p14 as a black knight
string p15 = BlackKnight;                   // initializes p15 as a black knight
string p16 = BlackKnight;                   // initializes p16 as a black knight
string p17 = BlackKnight;                   // initializes p17 as a black knight
string p18 = BlackKnight;                   // initializes p18 as a black knight
string p19 = BlackKnight;                   // initializes p19 as a black knight
string p20 = BlackKnight;                   // initializes p20 as a black knight
string p21 = WhiteKnight;                   // initializes p21 as a white knight
string p22 = BlackKnight;                   // initializes p22 as a black knight
string p23 = BlackKnight;                   // initializes p23 as a black knight
string p24 = BlackKnight;                   // initializes p24 as a black knight
string p25 = BlackKnight;                   // initializes p25 as a black knight



//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void displayWelcomeMessage()                    // creates a function that displays the welcome message
{
    cout << "Program 2: Knight Escape \n"
         << "CS 141, Spring 2022, UIC \n"
         << " \n"
         << "The objective of this puzzle is to get the white knight "
         << "up to the empty square in the top right corner of the board. "
         << "Use standard knight moves from a traditional chess game, "
         << "where a knight moves in an L-shape. \n"
         << "This means that a knight can only move either "
         << "1) two squares in a horizontal direction, then one in a vertical direction, OR "
         << "2) two squares in a vertical direction, then one in a horizontal direction."
         << " \n"
         << "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n"
         << "Try to complete the puzzle with the smallest number of valid moves!"
         << endl;
} //end displayWelcomeMessage()

    
// ----------------------------------------------------------------------
// Display the current board, along with the corresponding positions
// This function makes use of global variables p1..p25, which represent
// each of the positions on the board
void displayBoard()                     // creates a function that displays the current positions on the board
{
    cout <<"\n"
         <<                          "    Board   " <<                               "      Position \n"
         << " " <<  p1 << " " <<  p2 << " " <<  p3 << " " <<  p4 << " " <<  p5 << "     1  2  3  4  5 \n"
         << " " <<  p6 << " " <<  p7 << " " <<  p8 << " " <<  p9 << " " << p10 << "     6  7  8  9 10 \n"
         << " " << p11 << " " << p12 << " " << p13 << " " << p14 << " " << p15 << "    11 12 13 14 15 \n"
         << " " << p16 << " " << p17 << " " << p18 << " " << p19 << " " << p20 << "    16 17 18 19 20 \n"
         << " " << p21 << " " << p22 << " " << p23 << " " << p24 << " " << p25 << "    21 22 23 24 25 \n"
         << endl;
} //end displayBoard()



void resetDisplayBoard()                    // creates a function that resets the board when the user inputs 'R'
{
    p1 = BlackKnight;                       // resets p1 to a black knight
    p2 = BlackKnight;                       // resets p2 to a black knight
    p3 = BlackKnight;                       // resets p3 to a black knight
    p4 = BlackKnight;                       // resets p4 to a black knight
    p5 = BlankPosition;                     // resets p5 to a blank position
    p6 = BlackKnight;                       // resets p6 to a black knight
    p7 = BlackKnight;                       // resets p7 to a black knight
    p8 = BlackKnight;                       // resets p8 to a black knight
    p9 = BlackKnight;                       // resets p9 to a black knight
    p10 = BlackKnight;                      // resets p10 to a black knight
    p11 = BlackKnight;                      // resets p11 to a black knight
    p12 = BlackKnight;                      // resets p12 to a black knight
    p13 = BlackKnight;                      // resets p13 to a black knight
    p14 = BlackKnight;                      // resets p14 to a black knight
    p15 = BlackKnight;                      // resets p15 to a black knight
    p16 = BlackKnight;                      // resets p16 to a black knight
    p17 = BlackKnight;                      // resets p17 to a black knight
    p18 = BlackKnight;                      // resets p18 to a black knight
    p19 = BlackKnight;                      // resets p19 to a black knight
    p20 = BlackKnight;                      // resets p20 to a black knight
    p21 = WhiteKnight;                      // resets p21 to a white knight
    p22 = BlackKnight;                      // resets p22 to a black knight
    p23 = BlackKnight;                      // resets p23 to a black knight
    p24 = BlackKnight;                      // resets p24 to a black knight
    p25 = BlackKnight;                      // resets p25 to a black knight
    moveNumber = 1;
    score = 500;
    cout << "*** Restarting";
    displayBoard();
    cout << "Current score: " << score << endl;
    // resets moveNumber to the first move
} //end displayBoard()


void setValue(int square, string value) {   // switch cases for each of the p positions

    switch(square) {
        case 1:
            p1 = value;
            break;
        case 2:
            p2 = value;
            break;
        case 3:
            p3 = value;
            break;
        case 4:
            p4 = value;
            break;
        case 5:
            p5 = value;
            break;
        case 6:
            p6 = value;
            break;
        case 7:
            p7 = value;
            break;
        case 8:
            p8 = value;
            break;
        case 9:
            p9 = value;
            break;
        case 10:
            p10 = value;
            break;
        case 11:
            p11 = value;
            break;
        case 12:
            p12 = value;
            break;
        case 13:
            p13 = value;
            break;
        case 14:
            p14 = value;
            break;
        case 15:
            p15 = value;
            break;
        case 16:
            p16 = value;
            break;
        case 17:
            p17 = value;
            break;
        case 18:
            p18 = value;
            break;
        case 19:
            p19 = value;
            break;
        case 20:
            p20 = value;
            break;
        case 21:
            p21 = value;
            break;
        case 22:
            p22 = value;
            break;
        case 23:
            p23 = value;
            break;
        case 24:
            p24 = value;
            break;
        case 25:
            p25 = value;
            break;
    }
}

string getValue(int switchValue) {  // switch case that returns the value for each of the p functions

    switch(switchValue) {
        case 1:
            return p1;
            
        case 2:
            return p2;
            
        case 3:
            return p3;
            
        case 4:
            return p4;
            
        case 5:
            return p5;
            
        case 6:
            return p6;
            
        case 7:
            return p7;
            
        case 8:
            return p8;
            
        case 9:
            return p9;
            
        case 10:
            return p10;
            
        case 11:
            return p11;
            
        case 12:
            return p12;
            
        case 13:
            return p13;
            
        case 14:
            return p14;
            
        case 15:
            return p15;
            
        case 16:
            return p16;
            
        case 17:
            return p17;
            
        case 18:
            return p18;
            
        case 19:
            return p19;
            
        case 20:
            return p20;
            
        case 21:
            return p21;
            
        case 22:
            return p22;
            
        case 23:
            return p23;
            
        case 24:
            return p24;
            
        case 25:
            return p25;
        default:
            return " ";
            
    }
}
bool validPositionCheck(int from, int to)                       // bool function that checks if the user follows the allowed L path
{
    int rowf = (from-1) / 5;                                    //integer division to get row of from indexed at 0
    int colf = from - (5 * rowf);                               // find the column of from indexed at 1
    rowf++;                                                     //index both at 1


    int rowt = (to-1) / 5;                                     //integer division to get row of from indexed at 0
    int colt = to - (5 * rowt);                                // find the column of from indexed at 1
    rowt++;                                                    //index both at 1



    int differenceRow = abs(rowt - rowf);
    int differenceColumn = abs(colt - colf);                    // if an L shape movement has occured the knight moved 2 in a direction and 1 in                                                            // another
    if (differenceRow == 1)
    {
        if (differenceColumn == 2)
            return true;
        else
            return false;

    }
    else if(differenceRow == 2)
    {
        if (differenceColumn == 1)
            return true;
        else
            return false;

    }
    else
    return false;

}




// ----------------------------------------------------------------------
// Main() function of the program, containing the loop that controls
// game play
int main() {
   
   displayWelcomeMessage();               // displays the welcome message
    
    // Set board values to the default starting position
   // ...
    
   displayBoard();                        // displays the board with all the variables in the default position
   
   cout << "Current score: " << score << endl;
   // Loop that controls game play
   while(p5 != WhiteKnight) {               // loop that asks for the user input into menuOption, then quits if the user inputs 'X', resets the board to the                                                                    // default values if the user inputs 'R', and starts the game if the user inputs 'M'.
      cout << moveNumber << ". "
             << "Enter one of the following: \n"
             << "  - M to move a knight from one position to another, \n"
             << "  - R to reset the board back to the beginning, or \n"
             << "  - X to exit the game. \n"
             << "Your choice -> ";
        cin >> menuOption;                 // gets the menu option from the user's input
        menuOption = toupper(menuOption);  // convert user input to uppercase
        
       
        if (menuOption == 'X')            // if statement that breaks out of
        {                                 // the loop that controls the game play.
            cout << "Exiting..." << endl;
            break;                        //................................................
        }                                 //................................................
        
        
        
        else if (menuOption == 'R')       // else-if statement that resets the board
        {                                 // back to the beginning if the user inputs 'R'.
                         // ...............................................
            // ...............................................
            resetDisplayBoard();
            continue;
        }
        
        
        
        else if (menuOption == 'M')                             // else-if statement that executes if the user inputs 'M'
        {                                                       // asnd asks for the position of the knight to be moved to and from
            cout << "Enter the positions from and to, separated by a space (e.g. 14 5 to move the knight in position 14 to position 5):" << endl;  // ...............................................
            cin >> moveFrom;                                    // ...............................................
            cin >> moveTo;                                      // ...............................................
            
            cout<< "You have chosen to move a knight from position "<< moveFrom<< " to position "<< moveTo <<" .\n";
            
        }
        else {
            cout << "Invalid input not X R M (change this later) " << endl;
            continue;
        }
                                          
        
        if (moveFrom < 1 || moveFrom > 25)       // Check that FROM position is valid, i.e. within 1-25
        {
           cout << "The source position should be a valid position on the board (1-25). Try again."  << endl;
           score = score - 10;
            cout<< "Current score: "<< score << endl;
            if (score <= 0)
            {
              cout << "You have run out of moves. Try to do better next time!" << endl;
            break;
            }
       
           continue;
       }
        
       
       
       
       if (moveTo < 1 || moveTo > 25)          // Check that TO position is valid, i.e. within 1-25
       {
           cout << "The destination position should be a valid position on the board (1-25). Try again."  << endl;
           score = score - 10;
           cout << "Current score: "<< score << endl;
           if (score <= 0)
            {
              cout << "You have run out of moves. Try to do better next time!" << endl;
            break;
            }

           continue;
      }
   
    
       
       if (getValue(moveFrom) == BlankPosition)
    {
        cout << "The source position should have a knight. Try again." << endl;
        score = score - 10;
        cout << "Current score: "<< score << endl;
        if (score <= 0)
            {
              cout << "You have run out of moves. Try to do better next time!" << endl;
            break;
            }
        // Check that the source position has a knight
        continue;
    }
       
     
    
 
       if (getValue(moveTo) != BlankPosition)      // Check that the destination position is empty
       {
           cout << "The destination position should be empty. Try again." << endl;
           score = score - 10;
           cout << "Current score: " << score << endl;
           if (score <= 0)
            {
              cout << "You have run out of moves. Try to do better next time!" << endl;
            break;
            }
           continue;
       }

       //if movement valid
        if (!validPositionCheck(moveFrom, moveTo))
        {
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            score = score - 10;
            cout << "Current score: " << score << endl;
            if (score <= 0)
            {
              cout << "You have run out of moves. Try to do better next time!" << endl;
            break;
            }
            continue;
        }
        else {
            
            score = score - 5;                                     // checks if p5 is whiteknight and the score is above 0, outputs the congrats                                                       // line.
            blankPos = moveFrom;
            string temp = getValue(moveFrom);
            setValue(moveFrom,getValue(moveTo));                   // uses setValue to change the postion from-to a spot
            setValue(moveTo, temp); //position swap logic
            displayBoard();
            if (getValue(5) == WhiteKnight && score > 0 )
            {
              cout << endl;
              cout << "Congratulations, you did it!" << endl;
              break;
            }
            cout << "Current score: " << score << endl;            // and then outputs the current score and updates the move number
            moveNumber += 1;
            continue;
            
        }
    }
        
       
   cout << "Thank you for playing!" << endl;
    
    return 0;
    
   }
