/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: transform
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
/*
x, y, a, b reprsent indexes
x, y(currRow, currCol) -> a, b(nextRow, nextCol)
nextRow = currCol
nextCol = square.size() - 1 - currRow;
*/
void rotate(vector<vector<char>>& square) {
    vector<vector<char>> tempSquare = square;
    for (int i = 0; i < square.size(); ++i) {
        for (int j = 0; j < square.size(); ++j) {
            int nextRow = j;
            int nextCol = square.size() - 1 - i;
            square[nextRow][nextCol] = tempSquare[i][j];
        }
    }
}

/*
x, y, a, b reprsent indexes
x, y(currRow, currCol) -> a, b(nextRow, nextCol)
nextRow = currRow
nextCol = square.size() - 1 - currCol;
*/
void mirror(vector<vector<char>>& square) {
    for (int row = 0; row < square.size(); ++row) {
        for (int col = 0; col < square.size() / 2; ++col) {
            int nextRow = row;
            int nextCol = square.size() - 1 - col;
            swap(square[row][col], square[nextRow][nextCol]);
        }
    }
}


int main() {
    ofstream fout("transform.out");
    ifstream fin("transform.in");

    int n;
    fin >> n;
    vector<vector<char>> startingSquare(n, vector<char>(n));
    vector<vector<char>> endingSquare(n, vector<char>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> startingSquare[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> endingSquare[i][j];
        }
    }

    int res = -1;

    //check condition 1, 2, 3
    rotate(startingSquare);
    if (startingSquare == endingSquare) {
        res = 1;
    }
    rotate(startingSquare);
    if (res == -1 && startingSquare == endingSquare) {
        res = 2;
    }
    rotate(startingSquare);
    if (res == -1 && startingSquare == endingSquare) {
        res = 3;
    }
    rotate(startingSquare);

    //condition 4 
    mirror(startingSquare);
    if (res == -1 && startingSquare == endingSquare) {
        res = 4;
    }

    //condition 5
    for (int i = 0; i < 4; ++i) {
        rotate(startingSquare);
        if (res == -1 && startingSquare == endingSquare) {
            res = 5;
            break;
        }
    }

    //condition 6 
    if (res == -1 && startingSquare == endingSquare) {
        res = 6;
    }

    //condition 7
    if (res == -1) {
        res = 7;
    }

    fout << res << "\n";

    return 0;
}