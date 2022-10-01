//Name: Brandon Tran
//Date: 05/18/20
//Purpose: Create a Sudoku game

#include <iostream>	  // Access input output stream
using namespace std;    // Access cout, endl, cin

// All global variables here before main():

int countProblems = 0; // 0 means it is a winning game with no problems
int S2[9][9] = {       // game S1: 9x9 Sudoku game board
    {2,3,4,5,6,7,8} ,   // row 0          row 1 for player
    {5,6,7,8,9,2,3} ,   // row 1          row 2 for player
    {7,8,9,1,3,4,5,6} ,   // row 2          row 3 for player
    {2,3,5,6,7,8,9,1} ,   // row 3          row 4 for player
    {5,6,7,8,9,2,3,4} ,   // row 4          row 5 for player
    {8,9,2,3,4,5,6} ,   // row 5          row 6 for player
    {3,4,5,6,7,8,1,2} ,   // row 6          row 7 for player
    {7,8,9,1,3,4,5} ,   // row 7          row 8 for player
    {9,1,3,4,5,6,7} }; // row 8          row 9 for player
   // game S1 ends
int S1[9][9] = {       // game S1: 9x9 Sudoku game board
    {1,2,3,4,5,6,7,8,9} ,   // row 0          row 1 for player
    {4,6,7,8,9,1,2,3} ,   // row 1          row 2 for player
    {7,8,9,1,3,4,5,6} ,   // row 2          row 3 for player
    {2,3,4,5,5,7,8,9,1} ,   // row 3          row 4 for player
    {5,6,7,8,9,1,2,4} ,   // row 4          row 5 for player
    {8,9,1,2,3,4,5,6,7} ,   // row 5          row 6 for player
    {4,5,6,7,8,9,1,2} ,   // row 6          row 7 for player
    {6,7,8,9,1,2,3,4,5} ,   // row 7          row 8 for player
    {9,1,2,3,4,5,7,8} }; // row 8          row 9 for player
   // game S1 ends
int S3[9][9] = {       // game S1: 9x9 Sudoku game board
    {1,2,4,5,6,8} ,   // row 0          row 1 for player
    {5,6,7,8,1,2,3} ,   // row 1          row 2 for player
    {7,9,1,2,4,5,6} ,   // row 2          row 3 for player
    {3,4,6,8,9,1} ,   // row 3          row 4 for player
    {5,6,7,9,1,2,4} ,   // row 4          row 5 for player
    {8,1,2,3,4,5,7} ,   // row 5          row 6 for player
    {3,4,5,7,8,1,2} ,   // row 6          row 7 for player
    {6,7,9,1,2,3,5} ,   // row 7          row 8 for player
    {9,2,3,4,6,7} }; // row 8          row 9 for player
   // game S1 ends
int S4[9][9] = {       // game S1: 9x9 Sudoku game board
    {1,3,4,6,7,9} ,   // row 0          row 1 for player
    {5,7,8,1,3} ,   // row 3          row 4 for player
    {8,1,2,4,5} ,   // row 6          row 7 for player
    {2,4,5,7,8,1} ,   // row 3          row 4 for player
    {6,7,9,1,3} ,   // row 4          row 5 for player
    {8,1,3,5,6} ,   // row 7          row 8 for player
    {4,5,7,9,2} ,   // row 6          row 7 for player
    {6,8,1,3,4} ,   // row 7          row 8 for player
    {1,2,4,5,6,8} }; // row 8          row 9 for player
   // game S1 ends
void show(int S[9][9]);
void checkRow(int S[9][9], int row);
void checkColumn(int S[9][9], int column);
void checkSquare(int S[9][9], int square);
int unique9numbers(int D[9]); // array D has 9 numbers
void check(int S[9][9]);

int main() // like a driver to test all the functions
{ // begin of main() ====================================================.
    int n = 1; // line numbering control for separation lines
    cout << "Welcome to play the Sudoku Game Check of Brandon Tran!" << endl;
    cout << endl << n++ << "=================================================================." << endl;
    cout << "Your game 1 is as follows:";
    show(S1); // to show game board 9x9
    cout << "Your game 1:" << endl;
    check(S1); // to check game for all problems 
    cout << endl << n++ << "=================================================================." << endl;
    cout << "Your game 2 is as follows:";
    show(S2); // to show game board 9x9
    cout << "Your game 2:" << endl;
    check(S2); // to check game for all problems 
    cout << endl << n++ << "=================================================================." << endl;
    cout << "Your game 3 is as follows:";
    show(S3); // to show game board 9x9
    cout << "Your game 3:" << endl;
    check(S3); // to check game for all problems 
    cout << endl << n++ << "=================================================================." << endl;
    cout << "Your game 4 is as follows:";
    show(S4); // to show game board 9x9
    cout << "Your game 4:" << endl;
    check(S4); // to check game for all problems 
    cout << endl << n++ << "=================================================================." << endl;
    cout << "Thank you for playing the Sudoku Game Check of Brandon Tran!";                                                           
    cout << endl << n++ << "=================================================================." << endl;
} // end of main() =======================================================.

void check(int S[9][9]) // check this game for all 9 rows/columns/squares
{
    countProblems = 0;    // start with 0 for a new game check 
    for (int r = 0; r <= 8; ++r) checkRow(S, r);
    for (int c = 0; c <= 8; ++c) checkColumn(S, c);
    for (int q = 0; q <= 8; ++q) checkSquare(S, q);
    if (countProblems == 0)
        cout << "Congratulations! You won the game!" << endl;
} // END check( ) ===================================.

void show(int S[9][9]) {
    int x = 0;
    for (int r = 0; r < 9; ++r) {
        cout << endl;
        for (int c = 0; c < 9; ++c) {
            cout << S[r][c];
        }
    }
    cout << endl;
}
void checkRow(int S[9][9], int row) {
    int arrayOfNumbers[9] = { unique9numbers(S[row]) };
    for (int i = 0; i <= 8; ++i) {
        if (arrayOfNumbers[i] == 0) {
            S[row][i] = i + 1;
        }
    }
}
void checkColumn(int S[9][9], int column) {
    int newArray[9];
    int i = 0;
    for (int r = 0; r <= 8; ++r) {
        newArray[i] = S[r][column];
        i++;
    }
    for (int x = 0; x <= 8; ++x) {
        if (newArray[x] == false) {
            S[x][column] = x + 1;
        }
    }
}
void checkSquare(int S[9][9], int square) {
    int newArray[10];
    int i = 0;
    if (square < 3) {
        for (int r = 0; r < 3; ++r) {
            for (int c = 0 + (square * 3); c < 3 + (square * 3); ++c) {
                newArray[i] = S[r][c];
                i++;
            }
        }
        for (int x = 0; x <= 8; ++x) {
            if (newArray[x] == 0) {

            }
            }
    }
    if (square >= 3 && square < 6) {
        for (int r = 3; r < 6; ++r) {
            for (int c = 0 + ((square - 3) * 3); c < 3 + ((square - 3) * 3); ++c) {
                newArray[i] = S[r][c];
                i++;
            }
        }

        if (unique9numbers(newArray) == false) {
            countProblems += 1;
            cout << "Square " << square + 1 << " has a problem." << endl;
        }
    }
    if (square >= 6) {
        for (int r = 6; r < 9; ++r) {
            for (int c = 0 + ((square - 6) * 3); c < 3 + ((square - 6) * 3); ++c) {
                newArray[i] = S[r][c];
                i++;
            }
        }
        if (unique9numbers(newArray) == false) {
            countProblems += 1;
            cout << "Square " << square + 1 << " has a problem." << endl;
        }
    }
 }
int unique9numbers(int D[9]) // array D has 9 numbers
{ // returns true if all 9 numbers in array D are unique, false otherwise
    int oneFound{}, twoFound{}, threeFound{}, fourFound{}, fiveFound{}, sixFound{}, sevenFound{}, eightFound{}, nineFound{};
    for (int c = 0; c < 9; ++c) {
        if (D[c] == 1) {
            oneFound = 1;
        }
        if (D[c] == 2) {
            twoFound = 1;
        }
        if (D[c] == 3) {
            threeFound = 1;
        }
        if (D[c] == 4) {
            fourFound = 1;
        }
        if (D[c] == 5) {
            fiveFound = 1;
        }
        if (D[c] == 6) {
            sixFound = 1;
        }
        if (D[c] == 7) {
            sevenFound = 1;
        }
        if (D[c] == 8) {
            eightFound = 1;
        }
        if (D[c] == 9) {
            nineFound = 1;
        }
    }
        int arrayOfNumbers[9] = { oneFound,twoFound,threeFound,fourFound,fiveFound,sixFound,sevenFound, eightFound, nineFound };
        return 0;
}
