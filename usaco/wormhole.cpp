/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: wormhole
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

const int MAXN = 12;

int n, res;
int x[MAXN + 1], y[MAXN + 1];
int nextRight[MAXN + 1];
int paired[MAXN + 1];

bool cycle() {
    /*for (int i = 1; i <= n; ++i) {
        int visited[MAXN + 1]{ 0 };
        int curr = i;
        while (visited[curr] == false) {
            visited[curr] = true;
            curr = paired[curr];
            visited[curr] = true;
            curr = nextRight[curr];
            visited[curr] = true;

            if (curr == i) return true;
        }

    }*/

    /* for (int i = 1; i <= n; ++i) {
         std::cout << i << " | " << paired[i] << " ";
     }
     std::cout << endl; */

    for (int i = 1; i <= n; ++i) {
        int curr = i;
        for (int step = 1; step <= n; ++step) {
            curr = paired[curr];
            curr = nextRight[curr];
        }

        if (curr != 0) return true;
    }


    return false;
}

void solve() {

    //find unpaired element 
    int i;
    for (i = 1; i <= n; ++i) {
        if (paired[i] == 0) break;
    }

    //there are no unpaired elements 
    if (i > n) {
        if (cycle()) {
            res += 1;
        }
        return;
    }

    //iterate from i to n and find another unpaired element for i 
    for (int j = i + 1; j <= n; ++j) {
        if (paired[j] == 0) {
            paired[i] = j;
            paired[j] = i;

            solve();

            paired[i] = 0;
            paired[j] = 0;
        }
    }
}


int main() {
    ofstream fout("wormhole.out");
    ifstream fin("wormhole.in");

    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> x[i] >> y[i];
    }

    //calculated next right 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            //find the first element that is to the right 
            if (nextRight[i] == 0) {
                if (i != j && y[i] == y[j] && x[j] - x[i] >= 0) {
                    nextRight[i] = j;
                }
            }
            else if (i != j && y[i] == y[j] && x[j] - x[i] >= 0 && x[j] - x[i] < x[nextRight[i]] - x[i]) {
                nextRight[i] = j;
            }
        }
    }

    /*  cout << "next right: ";
      for (auto i : nextRight) {
          cout << i << " ";
      }
      cout << endl; */

    solve();
    fout << res << '\n';

    return 0;
}
