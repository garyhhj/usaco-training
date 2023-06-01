/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: prefix
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
#include <cstring>
#include <cmath>
#include <memory>
#include <assert.h>

typedef long long ll;
using namespace std;


vector<string> primitives;
string sequence;

bool match(const string& pri, int start, int end) {
    if (end - start != pri.size()) return false;
    if (end > sequence.size()) return false;

    //now they are same length and can just iterate and check 
    for (int i = 0; i < pri.size(); ++i) {
        if (pri[i] != sequence[start + i]) return false;
    }
    return true;
}

int main() {
    ofstream fout("prefix.out");
    ifstream fin("prefix.in");

    string pri;
    while (fin >> pri) {
        if (pri == ".") break;
        primitives.push_back(pri);
    }

    sequence = "";
    string line;
    while (fin >> line) {
        sequence += line;
    }

    vector<int> dp(sequence.size() + 1, 0);
    dp[0] = 1;


    for (int i = 0; i < dp.size(); ++i) {
        if (dp[i] == 0) continue;

        for (const string& pri : primitives) {
            //we check primitive against the sequences 
            if (i + pri.size() > sequence.size()) continue;
            if (sequence.substr(i, pri.size()) == pri) {
                dp[i + pri.size()] = 1;
            }
        }

    }


    for (int i = dp.size() - 1; i >= 0; --i) {
        if (dp[i]) {
            fout << i << "\n";
            break;
        }
    }


    return 0;
}

