/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: stamps
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

const int MAXN = 50;
const int MAXK = 200;
const int MAXVAL = 10000;
const int inf = 2000000000;

int n, k;

int dp[MAXK * MAXVAL + 1];
int stampVal[MAXN];


int main() {
    ofstream fout("stamps.out");
    ifstream fin("stamps.in");

    fin >> k >> n;
    for (int i = 0; i < n; ++i) {
        fin >> stampVal[i];
    }
    sort(stampVal, stampVal + n, greater<int>());

    //initialize 
    for (int i = 0; i < n; ++i) {
        dp[stampVal[i]] = 1;
    }

    //finish rest of dp table 
    for (int i = 1; i <= MAXK * MAXVAL; ++i) {
        if (dp[i] == 0) continue;
        if (dp[i] == k) continue;

        for (int j = 0; j < n; ++j) {
            if (i + stampVal[j] > MAXK * MAXVAL) continue;

            if (dp[i + stampVal[j]] == 0) dp[i + stampVal[j]] = dp[i] + 1;
            dp[i + stampVal[j]] = min(dp[i + stampVal[j]], dp[i] + 1);
        }
    }


    //check for consecutive non zero values 
    int res = 0;
    int count = 0;
    for (int i = 1; i <= MAXK * MAXVAL; ++i) {
        if (dp[i]) count += 1;
        else {
            res = max(res, count); count = 0;
        }
    }

    fout << max(res, count) << endl;

    return 0;
}