/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: nocows
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

const int MAXN = 200;
const int MAXK = 100;
const int UNVISITED = -1;

int dp[MAXN + 1][MAXK + 1]; //number of trees with certain amount of nodes and height modulo 9901 
int N, K;

void solve(int n, int k) {
    //base cases 
    if (k == 0 || n == 0 || n % 2 == 0 || 2 * k - 1 > n) {
        dp[n][k] = 0;

        return;
    }

    if (n == 1) {
        if (k == 1) {
            dp[n][k] = 1;

            return;
        }
        dp[n][k] = 0;
        return;
    }


    //we want n nodes 
    //this is the same as taking (n - 1) nodes from two different trees 
    dp[n][k] = 0;
    for (int i = 1; i < n - 1; i += 2) {
        int nodes = n - i - 1;
        for (int j = 0; j < k - 1; j++) {
            if (dp[nodes][k - 1] == UNVISITED) {
                solve(nodes, k - 1);
            }
            if (dp[i][j] == UNVISITED) {
                solve(i, j);
            }


            dp[n][k] += 2 * dp[i][j] * dp[nodes][k - 1];
            dp[n][k] %= 9901;
        }

        if (dp[i][k - 1] == UNVISITED) {
            solve(i, k - 1);
        }
        if (dp[nodes][k - 1] == UNVISITED) {
            solve(nodes, k - 1);
        }
        dp[n][k] += dp[i][k - 1] * dp[nodes][k - 1];
        dp[n][k] %= 9901;
    }


}

int main() {
    ofstream fout("nocows.out");
    ifstream fin("nocows.in");

    fin >> N >> K;

    for (int i = 0; i <= MAXN; ++i) {
        std::fill(dp[i], dp[i] + MAXK + 1, UNVISITED);
    }
    solve(N, K);

    /*cout << "dp array\n";
    cout << "i: 0  1  2  3  4  5  6  7  8 " << "\n";
    for (int i = 0; i <= N; ++i) {
        cout << i << "  ";
        for (int j = 0; j <= K; ++j) {
            if (dp[i][j] == -1) cout << "u, ";
            else cout << dp[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n\n"; */

    fout << dp[N][K] << '\n';
}

