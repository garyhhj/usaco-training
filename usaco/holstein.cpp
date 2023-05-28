/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: holstein
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


uint32_t getlsbBitIndex(uint32_t bit) {
    assert(bit != 0);

    uint32_t pos = 0;
    while (!(bit & 0x1)) {
        bit >>= 1;
        ++pos;
    }
    return pos;
}


int main() {
    ofstream fout("holstein.out");
    ifstream fin("holstein.in");

    int v;
    fin >> v;
    vector<int> reqv(v);
    for (int i = 0; i < v; ++i) {
        fin >> reqv[i];
    }

    int n;
    fin >> n;
    vector<vector<int>> feeds(n, vector<int>(v));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < v; ++j) {
            fin >> feeds[i][j];
        }
    }


    //iterate through bitmask and then find the smallest amount of feeds 
    int smallestAmount = n + 1;
    vector<int> feednum;

    uint32_t maxMask = 0x0;
    for (int i = 0; i < n; ++i) {
        maxMask <<= 1;
        maxMask |= 0x1;

    }

    for (uint32_t i = 0x1; i <= maxMask; ++i) {
        if (__builtin_popcount(i) >= smallestAmount) continue;
        uint32_t mask = i;
        vector<int> reqvitamin = reqv;
        vector<int> newfeednum;
        while (mask) {
            uint32_t index = getlsbBitIndex(mask);
            mask &= mask - 1;
            newfeednum.push_back(index);

            for (int i = 0; i < v; ++i) {
                reqvitamin[i] -= feeds[index][i];
            }
        }

        //check if all virtamins is zero or negative 
        bool metreq = true;
        for (int i = 0; i < reqvitamin.size(); ++i) {
            if (reqvitamin[i] > 0) {
                metreq = false;
                break;
            }
        }

        //update the feed required 
        if (metreq) {
            smallestAmount = __builtin_popcount(i);
            mask = i;
            feednum = newfeednum;
        }
    }

    fout << smallestAmount;
    for (int i = 0; i < feednum.size(); ++i) {
        fout << " " << feednum[i] + 1;
    }
    fout << "\n";


    return 0;
}
