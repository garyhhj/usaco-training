/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: kimbits
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
#include <bit>

using namespace std;
using ld = long double;
using ll = long long;

const int MAXN = 31;
const int inf = 2000000000;


ll bCoeff[MAXN + 1][MAXN + 1];
ll nums[MAXN + 1][MAXN + 1];

ll n, l, i;

int main() {
    ofstream fout("kimbits.out");
    ifstream fin("kimbits.in");

    fin >> n >> l >> i;

    //init binomial coefficients 
    for (int row = 0; row <= MAXN; ++row) {
        for (int col = 0; col <= MAXN; ++col) {
            if (col == 0 || col == row) bCoeff[row][col] = 1;
            else if (0 < col && col < row) {
                bCoeff[row][col] = bCoeff[row - 1][col - 1] + bCoeff[row - 1][col];
            }
        }
    }

    //init nums 
    for (int len = 0; len <= MAXN; ++len) {
        for (int choose = 0; choose <= MAXN; ++choose) {
            for (int i = 0; i <= choose; ++i) {
                nums[len][choose] += bCoeff[len][i];
            }
        }
    }

    for (int currPos = n; currPos >= 1; --currPos) {
        if (nums[currPos - 1][l] < i) {
            fout << 1;
            i -= nums[currPos - 1][l];
            l -= 1;
        }
        else {
            fout << 0;
        }
    }
    fout << endl;

    return 0;
}