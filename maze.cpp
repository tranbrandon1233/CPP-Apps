bool pathExists(string maze[], int nRows, int nCols,
    int sr, int sc, int er, int ec)
    // Return true if there is a path from (sr,sc) to (er,ec)
    // through the maze; return false otherwise
{
    if (sr == er && sc == ec)
        return true;
    
    maze[sr][sc] = 'P';

    bool east = false;
    bool north = false;
    bool west = false;
    bool south = false;
    
    //East
    if (maze[sr][sc + 1] != 'P' && maze[sr][sc + 1] != 'X') {
        east = pathExists(maze, nRows, nCols, sr, sc + 1, er, ec);
    }
    //North
    if (maze[sr - 1][sc] != 'P' && maze[sr - 1][sc] != 'X') {
        north = pathExists(maze, nRows, nCols, sr - 1, sc, er, ec);
    }
    //West
    if (maze[sr][sc - 1] != 'P' && maze[sr][sc - 1] != 'X') {
        west = pathExists(maze, nRows, nCols, sr, sc - 1, er, ec);
    }
    //South
    if (maze[sr + 1][sc] != 'P' && maze[sr+1][sc] != 'X') {
        south = pathExists(maze, nRows, nCols, sr + 1, sc, er, ec);
    }
    return east || north || west || south;
}

