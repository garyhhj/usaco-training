/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: butter
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

const int inf = 2000000000;
const int MAXN = 500;
const int MAXP = 800;

int n, p, c;

map<int, int> cow;
vector<vector<pair<int, int>>> adj(MAXP + 1);

int main() {
    ofstream fout("butter.out");
    ifstream fin("butter.in");

    fin >> n >> p >> c;

    int cowNode;
    for (int i = 0; i < n; ++i) {
        fin >> cowNode;
        cow[cowNode] += 1;
    }

    int s, t, w;
    for (int i = 0; i < c; ++i) {
        fin >> s >> t >> w;
        adj[s].push_back({ t, w });
        adj[t].push_back({ s, w });
    }

    int distance = inf;
    //iterate through each pasture 
    for (int pasture = 0; pasture <= MAXP; ++pasture) {
        if (adj[pasture].empty()) continue;

        //dijkstra 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, pasture });
        vector<bool> visited(MAXP + 1, false);

        int cowDistance = 0;
        while (!pq.empty()) {
            int currWeight = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            if (visited[currNode]) continue;

            //check for cows 
            if (cow.find(currNode) != cow.end()) {
                cowDistance += cow[currNode] * currWeight;
            }

            visited[currNode] = true;
            //iterate through each of our neighbours
            for (int i = 0; i < adj[currNode].size(); ++i) {
                int nextNode = adj[currNode][i].first;
                int nextWeight = adj[currNode][i].second;

                if (!visited[nextNode]) {
                    pq.push({ currWeight + nextWeight, nextNode });
                }
            }
        }
        distance = min(distance, cowDistance);
    }

    fout << distance << endl;
    return 0;
}
