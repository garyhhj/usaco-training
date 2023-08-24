/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: agrinet
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
#include <queue>
#include <math.h>

using namespace std;
using ld = long double;
using ll = long long;

const int MAXN = 100;
const int inf = 1e9 + 7;

int n;
int adjMatrix[MAXN][MAXN];

int main() {
    ofstream fout("agrinet.out");
    ifstream fin("agrinet.in");

    fin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> adjMatrix[i][j];
        }
    }

    //prim's 
    vector<bool> visited(MAXN, false); visited[0] = true;
    int numVisited = 1;
    vector<pair<int, int>> edges;
    while (numVisited != n) {

        //getting next neighbouring node 
        int dist = inf;
        int nextNeighbour = -1;
        int currNode = -1;
        for (int currV = 0; currV < n; ++currV) {
            if (!visited[currV]) continue;
            for (int neighbourV = 0; neighbourV < n; ++neighbourV) {
                if (currV == neighbourV || visited[neighbourV]) continue;
                if (adjMatrix[currV][neighbourV] < dist) {
                    dist = adjMatrix[currV][neighbourV];
                    nextNeighbour = neighbourV; currNode = currV;
                }
            }
        }

        //updating edge list and visited
        numVisited += 1;
        visited[nextNeighbour] = true;
        edges.push_back({ currNode, nextNeighbour });
    }

    //sum up values from edges 
    int minLength = 0;
    for (auto edge : edges) {
        minLength += adjMatrix[edge.first][edge.second];
    }
    fout << minLength << endl;

    return 0;
}
