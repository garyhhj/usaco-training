/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: ariprog
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXSEQNUM = 125000;
const int MINSEQNUM = 1;

int bisquare[MAXSEQNUM + 1];

bool hasSequence(int a, int b, int n) {
    for (int i = 1; i < n; ++i) {
        if (a + i * b > MAXSEQNUM || bisquare[a + i * b] == 0) return false;
    }
    return true;
}

int main() {
    ofstream fout("ariprog.out");
    ifstream fin("ariprog.in");

    int n, m;
    fin >> n >> m;

    for (int p = 0; p <= m; ++p) {
        for (int q = 0; q <= m; ++q) {
            bisquare[p * p + q * q] = 1;
        }
    }

    vector<pair<int, int>> res;
    //now can start searching for sequences in bisquare 
    for (int a = 0; a <= MAXSEQNUM; ++a) {
        if (bisquare[a]) {
            for (int b = 1; b <= 125000 / n; ++b) {
                if (hasSequence(a, b, n)) {
                    res.push_back({ b, a });
                }
            }
        }
    }

    sort(res.begin(), res.end());

    for (auto i : res) {
        fout << i.second << " " << i.first << "\n";
    }
    if (res.empty()) {
        fout << "NONE\n";
    }

    return 0;
}
