/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: comehome
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
const int MAXN = 26;
const int inf = 10e9 + 7;
vector<vector<pair<int, int>>> adjList(256);
int n;

int main() {
    ofstream fout("comehome.out");
    ifstream fin("comehome.in");

    fin >> n;
    char a, b;
    int w;
    for (int i = 0; i < n; ++i) {
        fin >> a >> b >> w;

        adjList[a].push_back({ b, w });
        adjList[b].push_back({ a, w });
    }


    //dijkstra 
    vector<int> dist(256, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({ 0, 'Z' });
    while (!que.empty()) {
        int currWeight = que.top().first;
        int currNode = que.top().second;
        que.pop();

        if (dist[currNode] <= currWeight) continue;
        dist[currNode] = currWeight;

        //add neighbouring nodes to que 
        for (int i = 0; i < adjList[currNode].size(); ++i) {
            int neighbour = adjList[currNode][i].first;
            que.push({ currWeight + adjList[currNode][i].second, neighbour });
        }
    }

    //iterate through distance 
    int resNode;
    int resDist = inf;
    for (int i = 'A'; i < 'Z'; ++i) {
        if (dist[i] < resDist) {
            resDist = dist[i];
            resNode = i;
        }
    }
    fout << char(resNode) << " " << resDist << endl;

    return 0;
}
