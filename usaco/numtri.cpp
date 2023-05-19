/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: numtri
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXR = 1000;

int numberTri[MAXR + 1][MAXR + 1];


int main() {
    ofstream fout("numtri.out");
    ifstream fin("numtri.in");

    int n;
    fin >> n;

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < row + 1; ++col) {
            fin >> numberTri[row][col];
        }
    }

    for (int row = n - 1; row >= 0; --row) {
        for (int col = 0; col < row + 1; ++col) {
            numberTri[row][col] += max(numberTri[row + 1][col], numberTri[row + 1][col + 1]);
        }
    }

    fout << numberTri[0][0] << "\n";

    return 0;
}
