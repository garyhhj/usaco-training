/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: hamming
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
#include <cmath>
#include <assert.h>

typedef long long ll;
using namespace std;

int n, b, d;

bool checkHammingDistance(vector<int>& res, uint32_t num) {
    for (int i = 0; i < res.size(); ++i) {
        if (__builtin_popcount(res[i] ^ num) < d) {
            return false;
        }
    }
    return true;
}

int main() {
    ofstream fout("hamming.out");
    ifstream fin("hamming.in");

    fin >> n >> b >> d;

    vector<int> res;

    uint32_t maxMask = 0x0;
    for (int i = 0; i < b; ++i) {
        maxMask <<= 1;
        maxMask |= 0x1;
    }

    for (uint32_t i = 0; i <= maxMask; ++i) {

        if (res.size() == n) break;

        //check if its hamming distance 
        if (checkHammingDistance(res, i)) {
            res.push_back(i);
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        if (i != 0 && i % 10 == 0)  fout << "\n";

        if (i == res.size() - 1) fout << res[i] << "\n";
        else if ((i + 1) % 10 == 0)fout << res[i];
        else fout << res[i] << " ";
    }

    return 0;
}

