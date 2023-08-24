/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: humble
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

const int MAXK = 100;
const int MAXCATEGORY = 10000;
const int inf = 2000000000;

ll primes[MAXK];
ll primeIndex[MAXK];
ll n, k;

int main() {
    ofstream fout("humble.out");
    ifstream fin("humble.in");

    fin >> n >> k;

    for (int i = 0; i < n; ++i) {
        fin >> primes[i];
    }

    vector<ll> humbleNums = { 1 };

    while (humbleNums.size() != k + 1) {

        ll nextNum = primes[0] * humbleNums[primeIndex[0]];
        for (int i = 1; i < n; ++i) {
            nextNum = min(nextNum, primes[i] * humbleNums[primeIndex[i]]);
        }
        humbleNums.push_back(nextNum);

        for (int i = 0; i < n; ++i) {
            if (primes[i] * humbleNums[primeIndex[i]] == nextNum) {
                primeIndex[i] += 1;
            }
        }
    }

    fout << humbleNums[k] << endl;
    return 0;
}
