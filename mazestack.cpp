#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Coord
{
public:
  Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
  int r() const { return m_r; }
  int c() const { return m_c; }
private:
  int m_r;
  int m_c;
};

bool pathExists(string maze[], int nRows, int nCols,
                int sr, int sc, int er, int ec)
    // Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
{
  stack<Coord> coordStack;
  // Create dynamically allocated array to store passedCoords coordinates
  string **passedCoords = new string*[nRows];
  bool endFound = false;
  for (int i = 0; i < nRows; i += 1) {
      passedCoords[i] = new string[nCols];
    for (int j = 0; j < nCols; j += 1)
        passedCoords[i][j] = ".";  // set all coordinates as unpassedCoords
  }
  coordStack.push(Coord(sr, sc)); //Push starting coord onto stack and set passedCoords to O at that coord
  passedCoords[sr][sc] = "O";
  while (!coordStack.empty()) {   //Loop for all of coordStack
    Coord currentCoord = coordStack.top();  // Check next coord
    // cerr << "(" << currentCoord.r() << "," << currentCoord.c() << ")" << endl;
    coordStack.pop();
    if (currentCoord.r() == er && currentCoord.c() == ec) {       //If end coord found, set endFound to true
      endFound = true;
      break;
    }

    // Check west
    Coord w = Coord(currentCoord.r(), currentCoord.c()-1);
    if (maze[w.r()][w.c()] != 'X' && passedCoords[w.r()][w.c()] != "O") {
      coordStack.push(w);
      passedCoords[w.r()][w.c()] = "O";
    }
    // Check east
    Coord e = Coord(currentCoord.r(), currentCoord.c() + 1);
    if (maze[e.r()][e.c()] != 'X' && passedCoords[e.r()][e.c()] != "O") {
      coordStack.push(e);
      passedCoords[e.r()][e.c()] = "O";
    }
	// Check north
    Coord n = Coord(currentCoord.r() - 1, currentCoord.c());
    if (maze[n.r()][n.c()] != 'X' && passedCoords[n.r()][n.c()] != "O") {
      coordStack.push(n);
      passedCoords[n.r()][n.c()] = "O";
    }
    // Check South
    Coord s = Coord(currentCoord.r()+1, currentCoord.c());
    if (maze[s.r()][s.c()] != 'X' && passedCoords[s.r()][s.c()] != "O") {
      coordStack.push(s);
      passedCoords[s.r()][s.c()] = "O";
    }
  }

  for (int i = 0; i < nRows; i += 1)  //Delete dynamically allocated array
    delete [] passedCoords[i];
  delete [] passedCoords;

  return endFound; //Return whether end was found
}

int main()
{
    string maze[10] = {
         "XXXXXXXXXX",
         "X..X...X.X",
         "X.XXXX.X.X",
         "X.X.X..X.X",
         "X...X.XX.X",
         "XXX......X",
         "X.X.XXXX.X",
         "X.XXX....X",
         "X...X..X.X",
         "XXXXXXXXXX"
    };

    if (pathExists(maze, 10, 10, 5, 3, 8, 8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}

