/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: frac1
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

typedef long long ll;
using namespace std;

bool coprime(int a, int b) {
    if (std::gcd(a, b) == 1) return true;
    return false;
}


int n;

int main() {
    ofstream fout("frac1.out");
    ifstream fin("frac1.in");
    fin >> n;

    auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first * b.second < b.first* a.second;
    };
    map<pair<int, int>, int, decltype(comp)> mp(comp);

    for (int d = 1; d <= n; ++d) {
        for (int i = 1; i < d; ++i) {
            if (coprime(d, i)) {
                ++mp[{i, d}];
            }
        }
    }
    ++mp[{0, 1}];
    ++mp[{1, 1}];

    for (auto i : mp) {
        fout << i.first.first << "/" << i.first.second << "\n";
    }

    return 0;
}
