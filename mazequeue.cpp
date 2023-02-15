#include <iostream>
#include <string>
#include <queue>
#include <cassert>

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
  queue<Coord> coordQueue;
  // Create dynamically allocated array of strings to track passedCoords coordinates
  string **passedCoords = new string*[nRows];
  bool endFound = false;   //Track if end was found
  for (int i = 0; i < nRows; i += 1) {
    passedCoords[i] = new string[nCols];
    for (int j = 0; j < nCols; j += 1)
      passedCoords[i][j] = ".";  //Set all coords in passedCoords to .
  }
  coordQueue.push(Coord(sr, sc));  //Push current coordinate onto queue
  passedCoords[sr][sc] = "O";  //Set passedCoords to O at current coord
  while (!coordQueue.empty()) {   //Loop for all of coordQueue
    Coord curr = coordQueue.front();  // Check next coord
    //cerr << "(" << curr.r() << "," << curr.c() << ")" << endl;
    coordQueue.pop();  //Remove coord
	if (curr.r() == er && curr.c() == ec) { //If the coord was the end coord, set endFound to true and break
      // arrived
      endFound = true;
      break;
    }

    // Check east
    Coord e = Coord(curr.r(), curr.c() + 1);
    if (maze[e.r()][e.c()] != 'X' && passedCoords[e.r()][e.c()] != "O") {
        coordQueue.push(e);
        passedCoords[e.r()][e.c()] = "O";
    }
    //Check north
    Coord n = Coord(curr.r() - 1, curr.c());
    if (maze[n.r()][n.c()] != 'X' && passedCoords[n.r()][n.c()] != "O") {
      coordQueue.push(n);
      passedCoords[n.r()][n.c()] = "O";
    }
    // Check west
    Coord w = Coord(curr.r(), curr.c()-1);
    if (maze[w.r()][w.c()] != 'X' && passedCoords[w.r()][w.c()] != "O") {
        coordQueue.push(w);
        passedCoords[w.r()][w.c()] = "O";
    }
    // Check south
    Coord s = Coord(curr.r()+1, curr.c());
    if (maze[s.r()][s.c()] != 'X' && passedCoords[s.r()][s.c()] != "O") {
      coordQueue.push(s);
      passedCoords[s.r()][s.c()] = "O";
    }

   

  }

  for (int i = 0; i < nRows; i += 1)  //Delete dynamically-allocated array
    delete [] passedCoords[i];
  delete [] passedCoords;

  return endFound;  //Return whether the end coord was found
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
