/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: fact4
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

const int MAXN = 4220;
const int inf = 2000000000;

int n;

int main() {
    ofstream fout("fact4.out");
    ifstream fin("fact4.in");

    fin >> n;

    int num2 = 0;
    int num5 = 0;
    int res = 1;
    for (int i = n; i > 0; --i) {
        int iCpy = i;
        while (iCpy % 10 == 0) iCpy /= 10;

        while (iCpy % 2 == 0)
            iCpy /= 2, num2 += 1;
        while (iCpy % 5 == 0)
            iCpy /= 5, num5 += 1;
        res *= iCpy;
        res %= 10;
    }

    int diff = num2 - num5;
    while (diff--) {
        res *= 2;
        res %= 10;
    }

    fout << res << endl;

    return 0;
}