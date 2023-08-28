/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: ratios
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
const int inf = 2000000000;

int targetFeed[3];
int feed1[3];
int feed2[3];
int feed3[3];

bool check(int i, int j, int k) {

    int ratio = 0;
    for (int feed = 0; feed < 3; ++feed) {
        int x = i * feed1[feed] + j * feed2[feed] + k * feed3[feed];
        if (x == 0 && targetFeed[feed] == 0) continue;
        if (x == 0 && targetFeed[feed] != 0) return false;
        if (targetFeed[feed] == 0 && x != 0) return false;

        if (x % targetFeed[feed] != 0) return false;

        int currRatio = x / targetFeed[feed];
        if (ratio == 0) ratio = currRatio;
        else if (ratio != currRatio) return false;
    }
    return true;
}

int main() {
    ofstream fout("ratios.out");
    ifstream fin("ratios.in");

    for (int i = 0; i < 3; ++i) fin >> targetFeed[i];
    for (int i = 0; i < 3; ++i) fin >> feed1[i];
    for (int i = 0; i < 3; ++i) fin >> feed2[i];
    for (int i = 0; i < 3; ++i) fin >> feed3[i];


    int total = inf;
    int a, b, c;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            for (int k = 0; k < MAXN; ++k) {
                if (i + j + k < total && check(i, j, k)) {
                    total = i + j + k;
                    a = i; b = j; c = k;
                }
            }
        }
    }

    if (total != inf) {
        fout << a << " " << b << " " << c << " ";
        int gRatio = 0;
        for (int i = 0; i < 3; ++i) {
            if (targetFeed[i] == 0) continue;
            int currTotal = a * feed1[i] + b * feed2[i] + c * feed3[i];
            gRatio = max(gRatio, currTotal / targetFeed[i]);
        }
        fout << gRatio << endl;
    }
    else {
        fout << "NONE" << endl;
    }

    return 0;
}
