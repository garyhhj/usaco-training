/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: inflate
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

const int MAXMIN = 10000;
const int MAXCATEGORY = 10000;
const int inf = 1e9 + 7;

int minute, ptype;
int dp[MAXMIN + 1];
int points[MAXCATEGORY];
int minutes[MAXCATEGORY];


int main() {
    ofstream fout("inflate.out");
    ifstream fin("inflate.in");

    fin >> minute >> ptype;
    for (int i = 0; i < ptype; ++i) {
        fin >> points[i] >> minutes[i];
    }

    for (int i = 0; i <= minute; ++i) {
        for (int j = 0; j < ptype; ++j) {
            if (i + minutes[j] <= minute) {
                dp[i + minutes[j]] = max(dp[i + minutes[j]], dp[i] + points[j]);
            }
        }
    }

    fout << dp[minute] << endl;
    return 0;
}
