/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: cowtour
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;
using ld = long double;
const int MAXN = 150;
const int inf = 10e9 + 7;

int adjMatrix[MAXN][MAXN];
ld dist[MAXN][MAXN];
ld diameter[MAXN];
int x[MAXN];
int y[MAXN];
int n;

ld distance(int i, int j) {
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ofstream fout("cowtour.out");
    ifstream fin("cowtour.in");
    fin >> n;

    for (int i = 0; i < n; ++i) {
        fin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) {
        string row;
        fin >> row;
        for (int j = 0; j < n; ++j) {
            adjMatrix[i][j] = (row[j] == '0' ? 0 : 1);
        }
    }


    //floyd warshall
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
            if (adjMatrix[i][j]) dist[i][j] = distance(i, j);
            if (i == j) dist[i][j] = 0;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }



    //precalculate all current diameter 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == inf) continue;
            diameter[i] = max(diameter[i], dist[i][j]);
        }
    }

    //check all pairs 
    ld res = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == inf) {
                res = min(res, diameter[i] + diameter[j] + distance(i, j));
            }
        }
    }

    //check diameter without connecting 
    for (int i = 0; i < n; ++i) {
        res = max(res, diameter[i]);
    }

    fout << fixed << setprecision(6) << res << endl;

    return 0;
}
