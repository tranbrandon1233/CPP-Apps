#include <string>         // for string input

#include <iostream>    // Access input output stream

using namespace std;    // Access cout, endl, cin

// All global variables here

int countProblems = 0; // 0 at the end means it is a winning game

int S1[9][9] = {   // Sudoku game S1: 9 rows x 9 columns

     {1,2,3,4,5,6,7,8,9} ,

     {2,5,4,5,6,7,8,9,1} ,

     {7,8,9,6,7,8,9,1,2} ,

     {4,5,6,7,8,9,1,2,3} ,

     {5,6,7,8,9,1,2,3,4} ,

     {6,7,8,9,1,2,3,4,5} ,

     {7,8,9,1,2,3,4,5,6} ,

     {8,9,1,2,3,4,1,2,3} ,

     {9,1,2,3,4,5,9,7,8} }; // Sudoku game S1 

void show(int S[9][9]) // Sudoku game board 9x9

{ // begin show( )

    for (int r = 0; r <= 8; ++r)

    {
        for (int c = 0; c <= 8; ++c)

            cout << S[r][c]; //same line print

        cout << endl; // to end current row print

    }

} // end show( ) =================================

void checkSquare1(int S[9][9]) // check Square 1 only

{  // BEGIN checkSquare1( )  // Square 1 only

   // ENTER YOUR CODE HERE -----------------
    int newArray[10]; int i = 0; 
    for (int r = 0; r < 3; ++r) { 
        for (int c = 0; c < 3; ++c) { newArray[i] = S[r][c]; i++; } 
    }

    int oneFound{}, twoFound{}, threeFound{}, fourFound{}, fiveFound{}, sixFound{}, sevenFound{}, eightFound{}, nineFound{}; 
    for (int c = 0; c < 9; ++c) { 
        if (newArray[c] == 1) { oneFound = 1; }
        if (newArray[c] == 2) { twoFound = 1; }
        if (newArray[c] == 3) { threeFound = 1; }
        if (newArray[c] == 4) { fourFound = 1; }
        if (newArray[c] == 5) { fiveFound = 1; }
        if (newArray[c] == 6) { sixFound = 1; }
        if (newArray[c] == 7) { sevenFound = 1; }
        if (newArray[c] == 8) { eightFound = 1; }
        if (newArray[c] == 9) { nineFound = 1; } }
    int arrayOfNumbers[9] = { oneFound,twoFound,threeFound,fourFound,fiveFound,sixFound,sevenFound, eightFound, nineFound }; 
    int sumOfNumbers{}; 
    for (i = 0; i < 9; i++) { sumOfNumbers += arrayOfNumbers[i]; }
    if (sumOfNumbers != 9) { countProblems += 1; cout << "Square 1 has a problem." << endl; }
};
   // --------------------------------------
 // END checkSquare1( )  ================.



void checkSquare9(int S[9][9]) // check Square 9 only

{  // BEGIN checkSquare9( )  // Square 9 only

   // ENTER YOUR CODE HERE -----------------
    int newArray[10]; int i = 0;
    for (int r = 6; r < 9; ++r) {
        for (int c = 6; c < 9; ++c) { newArray[i] = S[r][c]; i++; }
    }
    int oneFound{}, twoFound{}, threeFound{}, fourFound{}, fiveFound{}, sixFound{}, sevenFound{}, eightFound{}, nineFound{};
    for (int c = 0; c < 9; ++c) {
        if (newArray[c] == 1) { oneFound = 1; }
        if (newArray[c] == 2) { twoFound = 1; }
        if (newArray[c] == 3) { threeFound = 1; }
        if (newArray[c] == 4) { fourFound = 1; }
        if (newArray[c] == 5) { fiveFound = 1; }
        if (newArray[c] == 6) { sixFound = 1; }
        if (newArray[c] == 7) { sevenFound = 1; }
        if (newArray[c] == 8) { eightFound = 1; }
        if (newArray[c] == 9) { nineFound = 1; }
    }
    int arrayOfNumbers[9] = { oneFound,twoFound,threeFound,fourFound,fiveFound,sixFound,sevenFound, eightFound, nineFound };
    int sumOfNumbers{};
    for (i = 0; i < 9; i++) { sumOfNumbers += arrayOfNumbers[i]; }
    if (sumOfNumbers != 9) { countProblems += 1; cout << "Square 9 has a problem." << endl; }
   // --------------------------------------

}; // END checkSquare9( ) ================.

int main()

{ // begin of main()

    cout << "Your game S1 is as follows:" << endl;

    show(S1); // show game board 9x9

    cout << "Your game S1:" << endl;

    checkSquare1(S1); // check Square 1 only

    checkSquare9(S1); // check Square 2 only

    if (countProblems == 0)

        cout << "Congratulations! You won the game!" << endl;

    cout << "==== Please enter a number to quit > " << endl;

    int k; cin >> k; return 0;

} // end of main() // =======================.