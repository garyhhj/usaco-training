/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: ttwo
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <cmath>
#include <memory>
#include <assert.h>

typedef long long ll;
using namespace std;

const int north = 1;
const int east = 2;
const int south = 3;
const int west = 4;
const int visited = 1;

char forest[10][10];
int visit[10][10][10][10][5][5] = { 0 }; //y and x for jon and then y and x for cow and then direction for jon and cow 

pair<int, int> fj;
pair<int, int> cow;
int fjd = north;
int cowd = north;

bool inRange(int x, int y) {
    if (x < 0 || y < 0) return false;
    if (x >= 10 || y >= 10) return false;
    return true;
}

void update(pair<int, int>& e, int& d) {

    //can use two direction arrays for this 
    bool canMove = false;
    if (d == north && inRange(e.first - 1, e.second) && forest[e.first - 1][e.second] != '*') {
        e.first = e.first - 1;
        canMove = true;
    }
    if (d == east && inRange(e.first, e.second + 1) && forest[e.first][e.second + 1] != '*') {
        e.second = e.second + 1;
        canMove = true;
    }
    if (d == south && inRange(e.first + 1, e.second) && forest[e.first + 1][e.second] != '*') {
        e.first = e.first + 1;
        canMove = true;
    }
    if (d == west && inRange(e.first, e.second - 1) && forest[e.first][e.second - 1] != '*') {
        e.second = e.second - 1;
        canMove = true;
    }

    if (!canMove) {
        //turn 90 clockwise 
        int arr[] = { 1, 2, 3, 4, 1 };
        d = arr[d];
    }

}

bool res = false;
int minutes = 0;
void solve() {

    while (true) {

        //cows and john meet 
        if (fj.first == cow.first && fj.second == cow.second) {
            //cout << "cow meet john" << endl; 
            //cout << "fj: " << fj.first << ", " << fj.second << " cow: " << cow.first << ", " << cow.second << "\n";

            res = true;
            break;
        }

        //there is a cycle 
        if (visit[fj.first][fj.second][cow.first][cow.second][fjd][cowd] == visited) {
            //cout << "cycle" << endl; 
            //cout << "fj: " << fj.first << ", " << fj.second << " cow: " << cow.first << ", " << cow.second << "\n";

            res = false;
            break;
        }

        visit[fj.first][fj.second][cow.first][cow.second][fjd][cowd] = visited;

        //check if can go forward and if not then turn 
        update(fj, fjd);
        update(cow, cowd);
        //cout << "fj: " << fj.first << ", " << fj.second << " cow: " << cow.first << ", " << cow.second << "\n";
        minutes += 1;
    }
}

int main() {
    ofstream fout("ttwo.out");
    ifstream fin("ttwo.in");


    string line;
    for (int i = 0; i < 10; ++i) {
        fin >> line;
        //cout << line << '\n'; 
        for (int j = 0; j < 10; ++j) {
            //  cout << line[j] << ", "; 
            forest[i][j] = line[j];
            if (forest[i][j] == 'F') fj = { i, j };
            if (forest[i][j] == 'C') cow = { i, j };
        }
        //cout << "\n"; 
    }

    solve();

    if (res) fout << minutes << "\n";
    else fout << "0\n";

    /*   cout << "forest\n";
       for (int i = 0; i < 10; ++i) {
           for (int j = 0; j < 10; ++j) {
               cout << char(forest[i][j]) << " ";
           }
           cout << "\n";
       }*/
}

