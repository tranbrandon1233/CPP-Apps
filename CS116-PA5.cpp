//Author: Brandon Tran
//Date: 05/13/20
//Purpose: Check who wins a game of Tic-Tac-Toe

#include <string>	  // for string input
#include <iostream>	  // Access input output stream
using namespace std;    // Access cout, endl, cin
// All global variables here:
char X = 'X', O = 'O'; // a nice way to initialize 6 games
char ttt[6][3][3] =  // 6x3x3 array to hold 6 preset games: 6 3X3 games
{ {	{O, O, O}, // Game 1 is ttt[0]  
        {O, O, O},
    {O, O, O} },
   {	{X, X, X}, // Game 2 is ttt[1]
    {X, X, X},
    {X, X, X} },
   {	{X, O, X}, // Game 3 is ttt[2]
    {X, X, O},
    {X, O, O} },
   {	{X, O, O}, // Game 4 is ttt[3]
    {O, X, O},
    {X, X, O} },
   {	{X, O, X}, // Game 5 is ttt[4]
    {O, X, O},
    {X, O, O} },
   {	{O, X, O}, // Game 6 is ttt[5]  - It is a tie.
    {X, O, X},
{X, O, X} } }; // end of ttt[6][3][3] array setup

void show(char t[3][3]);
void checkwin(char t[3][3]);
int main() {
    string T;     // to get 9 chars in as a string   
    char G[3][3]; // Game board 3 X 3 : 3 rows and 3 columns/row    
    char p;       // player p can be ‘O’ or ‘X’ 
    int n = 1;    // line numbering for separation lines
    int m = 6;   // game number on the output: GAME 7 8 9  
    int x = 0;    //Interate for length of string x
    cout << "Welcome to the TicTacToe Game Check of Brandon Tran!" << endl;
    for (int i = 0; i <= 5; ++i) // to check 6 games: SUB: 0 1 2 3 4 5
    {	                         //                   GAME: 1 2 3 4 5 6 
        cout << n++ << "===========================================================" << endl;
        cout << "GAME " << (i + 1) << " is as follows:" << endl; // GAME 1,2,3,4,5,6 
        show(ttt[i]);     // show the i-th game.  i = 0,1,2,3,4,5
        checkwin(ttt[i]); // check the i-th game. i = 0,1,2,3,4,5
    }
    while (true) {
        cout << n++ << "===========================================================" << endl;
        cout << "Please enter your game board(*to exit) > ";
        cin >> T; // get the string of 9 characters into T
        if (T == "*") {
            cout << "Thank you for playing this Tic-Tac-Toe Game Check of Brandon Tran!" << endl;
            cout << n++ << "===========================================================" << endl;
            break;
        }
        cout << "GAME " << (m + 1) << " is as follows:" << endl; // Track game number
        m++; //Increase game number
        for (int r = 0; r < 3; ++r) { //Iterate for each row
            for (int c = 0; c < 3; ++c) { //Iterate for each character,
                G[r][c] = T[x]; //Assign each character of string T to the matrix G
                x++; //Move on to next character in T
                if (r == 2 && c == 2)
                    x = 0; //Reset x
            }
        }
        show(G);     // show the game
        checkwin(G); // check the game
    }
}

void show(char t[3][3]) {
    int x = 0;
    for (int r = 0; r < 3; ++r) {
        cout << endl;
        for (int c = 0; c < 3; ++c) {
            cout << t[r][c];
        }
    }
    cout << '\n' << endl;
}

bool winrow1(char t[3][3], char p) //check whether row1 won by player p
{
    int r = 0;   //for board row 1 ; p can be ‘X’|‘O’; t is 3x3 game board
    return (t[r][0] == t[r][1] and t[r][1] == t[r][2] and t[r][2] == p);
} // return true | false 

bool winrow2(char t[3][3], char p) {
    int r = 1;   //for board row 2 ; p can be ‘X’|‘O’; t is 3x3 game board
    return (t[r][0] == t[r][1] and t[r][1] == t[r][2] and t[r][2] == p);
} // return true | false  // p can be ‘X’|‘O’
bool winrow3(char t[3][3], char p) {
    int r = 2;   //for board row 3 ; p can be ‘X’|‘O’; t is 3x3 game board
    return (t[r][0] == t[r][1] and t[r][1] == t[r][2] and t[r][2] == p);
} // return true | false // p can be ‘X’|‘O’

bool wincol1(char t[3][3], char p) {
    int c = 0;   //for board row 3 ; p can be ‘X’|‘O’; t is 3x3 game board
    return (t[0][c] == t[1][c] and t[1][c] == t[2][c] and t[2][c] == p);
} // return true | false // p can be ‘X’|‘O’// p can be ‘X’|‘O’
bool wincol2(char t[3][3], char p) {
    int c = 1;   //for board row 3 ; p can be ‘X’|‘O’; t is 3x3 game board
    return (t[0][c] == t[1][c] and t[1][c] == t[2][c] and t[2][c] == p);
} // return true | false // p can be ‘X’|‘O’// p can be ‘X’|‘O’
bool wincol3(char t[3][3], char p) {
    int c = 2;   //for board row 3 ; p can be ‘X’|‘O’; t is 3x3 game board
    return (t[0][c] == t[1][c] and t[1][c] == t[2][c] and t[2][c] == p);
} // return true | false // p can be ‘X’|‘O’// p can be ‘X’|‘O’

bool windia1(char t[3][3], char p) {
    return (t[0][0] == t[1][1] and t[1][1] == t[2][2] and t[2][2] == p);
} // p can be ‘X’|‘O’

bool windia2(char t[3][3], char p) // if diagonal2 won by player p:'X'|'O'
{
    return (t[0][2] == t[1][1] and t[1][1] == t[2][0] and t[2][0] == p);
}

void checkwin(char t[3][3])  // to check all winning situations   
{ // begin of checkwin( )
    int wincount = 0;  // count the winning situations
    if (winrow1(t, X))
    {
        cout << X << " won by row 1" << endl; ++wincount;
    }
    if (winrow1(t, O))
    {
        cout << O << " won by row 1" << endl; ++wincount;
    }
    if (winrow2(t, X))
    {
        cout << X << " won by row 2" << endl; ++wincount;
    }
    if (winrow2(t, O))
    {
        cout << O << " won by row 2" << endl; ++wincount;
    }
    if (winrow3(t, X))
    {
        cout << X << " won by row 3" << endl; ++wincount;
    }
    if (winrow3(t, O))
    {
        cout << O << " won by row 3" << endl; ++wincount;
    }
    if (wincol1(t, X))
    {
        cout << X << " won by column 1" << endl; ++wincount;
    }
    if (wincol1(t, O))
    {
        cout << O << " won by column 1" << endl; ++wincount;
    }
    if (wincol2(t, X))
    {
        cout << X << " won by column 2" << endl; ++wincount;
    }
    if (wincol2(t, O))
    {
        cout << O << " won by column 2" << endl; ++wincount;
    }
    if (wincol3(t, X))
    {
        cout << X << " won by column 3" << endl; ++wincount;
    }
    if (wincol3(t, O))
    {
        cout << O << " won by column 3" << endl; ++wincount;
    }
    if (windia1(t, X))
    {
        cout << X << " won by diagonal 1" << endl; ++wincount;
    }
    if (windia1(t, O))
    {
        cout << O << " won by diagonal 1" << endl; ++wincount;
    }
    if (windia2(t, X))
    {
        cout << X << " won by diagonal 2" << endl; ++wincount;
    }
    if (windia2(t, O))
    {
        cout << O << " won by diagonal 2" << endl; ++wincount;
    }
    if (wincount == 0) cout << "It is a tie." << endl;
};  // end of checkwin( )