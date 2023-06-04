/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: concom
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


const int MAXN = 100;
const int UNVISITED = -1.0f;
int n;
int percent[MAXN + 1][MAXN + 1];
bool visited[MAXN + 1][MAXN + 1];


vector<vector<pair<int, int>>> adj(MAXN + 1);


void dfs(int a, int other) {
    if (visited[a][other]) return;
    visited[a][other] = true;

    for (int i = 0; i < adj[other].size(); ++i) {
        int b = adj[other][i].first;
        percent[a][b] += adj[other][i].second;
        if (percent[a][b] > 50) dfs(a, b);
    }
}

int main() {
    ofstream fout("concom.out");
    ifstream fin("concom.in");

    int n;
    fin >> n;

    int i, j, p;
    for (int index = 0; index < n; ++index) {
        fin >> i >> j >> p;
        adj[i].push_back({ j, p });
    }

    for (int a = 1; a <= MAXN; ++a) {
        dfs(a, a);
    }


    for (int a = 1; a <= MAXN; ++a) {
        for (int b = 1; b <= MAXN; ++b) {
            if (percent[a][b] > 50 && a != b) {
                fout << a << " " << b << "\n";
            }
        }
    }
}

