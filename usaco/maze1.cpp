/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: maze1
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <cmath>
#include <memory>
#include <assert.h>
#include <climits>

typedef long long ll;
using namespace std;

const int UNVISITED = INT_MIN;

int w, h;

bool inrange(int y, int x) {
    if (x < 0 || y < 0) return false;
    if (x > 2 * w || y > 2 * h) return false;
    return true;
}

void bfs(queue<pair<int, int>>& que, vector<vector<int>>& visited, const vector<string>& maze) {
    vector<int> arrdx = { 0, 0, 2, -2 };
    vector<int> arrdy = { -2, 2, 0, 0 };
    while (!que.empty()) {
        int currx = que.front().second;
        int curry = que.front().first;
        int currw = visited[curry][currx];

        que.pop();

        for (int i = 0; i < 4; ++i) {
            int dx = arrdx[i];
            int dy = arrdy[i];

            if (inrange(curry + dy, currx + dx) &&
                maze[curry + dy / 2][currx + dx / 2] == ' ' &&
                visited[curry + dy][currx + dx] == UNVISITED) {
                que.push({ curry + dy, currx + dx });
                visited[curry + dy][currx + dx] = currw + 1;
            }
        }
    }
}


int main() {
    ofstream fout("maze1.out");
    ifstream fin("maze1.in");

    //get input 
    fin >> w >> h;
    fin.ignore();
    vector<string> maze(2 * h + 1);
    vector<vector<int>> visited1(2 * h + 1, vector<int>(2 * w + 1, UNVISITED));
    vector<vector<int>> visited2(2 * h + 1, vector<int>(2 * w + 1, UNVISITED));


    vector<pair<int, int>> temp;
    int row = 0;
    while (getline(fin, maze[row])) {

        //check for left and right as empty 
        if (maze[row][0] == ' ') {
            temp.push_back({ row, 1 });
        }
        if (maze[row][2 * w] == ' ') {
            temp.push_back({ row, 2 * w - 1 });
        }

        ++row;
        if (row == 2 * h + 1) break;
    }


    //check above and below 
    for (int i = 0; i <= 2 * w; ++i) {
        if (maze[0][i] == ' ') {
            temp.push_back({ 1, i });
        }

        if (maze[2 * h][i] == ' ') {
            temp.push_back({ 2 * h - 1, i });
        }
    }



    queue<pair<int, int>> que;
    que.push({ temp[0].first, temp[0].second });
    visited1[temp[0].first][temp[0].second] = 1;
    bfs(que, visited1, maze);

    que.push({ temp[1].first, temp[1].second });
    visited2[temp[1].first][temp[1].second] = 1;
    bfs(que, visited2, maze);


    int res = 0;
    //iterate through both visited2 and find the max values 
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int y = 1 + i * 2;
            int x = 1 + j * 2;

            int temp = min(visited1[y][x], visited2[y][x]);
            res = max(res, temp);
        }
    }

    cout << res << '\n';
}

