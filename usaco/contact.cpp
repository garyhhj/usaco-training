/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: contact
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

string text;
int a, b, n;

struct comp {
    bool operator()(const string& rhs, const string& lhs) {
        if (rhs.size() < lhs.size()) return true;
        if (rhs.size() > lhs.size()) return false;
        return rhs < lhs;
    }
};

int main() {
    ofstream fout("contact.out");
    ifstream fin("contact.in");

    fin >> a >> b >> n;
    fin >> text;
    while (fin) {
        string temp;
        fin >> temp;
        text += temp;
    }

    //sliding windows 
    map<string, int> freq;
    for (int i = a; i <= b; ++i) {
        for (int j = 0; j + i <= text.size(); ++j) {
            freq[text.substr(j, i)] += 1;
        }
    }

    map<int, vector<string>, greater<int>> sortedResult;
    for (auto& kv : freq) {
        sortedResult[kv.second].push_back(kv.first);
    }

    int count = 0;
    for (auto& kv : sortedResult) {
        sort(kv.second.begin(), kv.second.end(), comp());
        fout << kv.first << "\n";

        int lineCount = 0;
        for (int i = 0; i < kv.second.size() - 1; ++i) {
            fout << kv.second[i];
            lineCount += 1;
            fout << (lineCount == 6 ? "\n" : " ");
            if (lineCount == 6) lineCount = 0;
        }
        fout << kv.second[kv.second.size() - 1] << "\n";

        count += 1;
        if (count == n) break;
    }


    return 0;
}
