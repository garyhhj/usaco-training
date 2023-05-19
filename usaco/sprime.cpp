/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: sprime
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;

int n;
vector<int> primenums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
vector<int> res;

bool isPrime(int num) {
    if (num == 1) return false;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int currnum = 0;
void dfs(int depth) {
    if (!isPrime(currnum) && currnum != 0) {
        return;
    }

    if (depth == n) {
        res.push_back(currnum);
        return;
    }

    int currnumCpy = currnum;
    for (int i = 0; i < primenums.size(); ++i) {
        currnum *= 10;
        currnum += primenums[i];
        dfs(depth + 1);
        currnum = currnumCpy;
    }
}

int main() {
    ofstream fout("sprime.out");
    ifstream fin("sprime.in");

    fin >> n;

    dfs(0);

    for (auto i : res) {
        fout << i << "\n";
    }


    return 0;
}
