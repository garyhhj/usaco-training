/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: money
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

int n, v;

const int MAXN = 10000;
const int MAXV = 25;

int coin[MAXV];
ll dp[MAXN + 1];


int main() {
    ofstream fout("money.out");
    ifstream fin("money.in");

    fin >> v >> n;

    for (int i = 0; i < v; ++i) {
        fin >> coin[i];
    }

    dp[0] = 1;
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j <= MAXN; ++j) {
            if (j + coin[i] <= MAXN) {
                dp[j + coin[i]] += dp[j];
            }
        }
    }
    fout << dp[n] << '\n';

    return 0;
}

