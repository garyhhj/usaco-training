/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: crypt1
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

bool check(int num, map<int, bool> mp) {
    while (num) {
        if (mp.find(num % 10) == mp.end()) return false;
        num /= 10;
    }
    return true;
}


int main() {
    ofstream fout("crypt1.out");
    ifstream fin("crypt1.in");

    int n;
    fin >> n;
    vector<int> digits(n);
    map<int, bool> mp;
    for (int i = 0; i < n; ++i) {
        fin >> digits[i];
        mp[digits[i]] = true;
    }

    int res = 0;
    for (int aindex = 0; aindex < n; ++aindex)
        for (int bindex = 0; bindex < n; ++bindex)
            for (int cindex = 0; cindex < n; ++cindex)
                for (int dindex = 0; dindex < n; ++dindex)
                    for (int eindex = 0; eindex < n; ++eindex) {
                        int a = digits[aindex];
                        int b = digits[bindex];
                        int c = digits[cindex];
                        int d = digits[dindex];
                        int e = digits[eindex];

                        int abc = a * 100 + b * 10 + c;
                        int p1 = abc * d;
                        int p2 = abc * e;
                        int p = p2 + 10 * p1;
                        if (p1 <= 999 && p1 >= 100 && p2 <= 999 && p2 >= 100 && p <= 9999 && p >= 1000 && check(p1, mp) && check(p2, mp) && check(p, mp)) {
                            res += 1;

                            //cout << abc << " * " << d << e << " = " << p2 << " + " << 10 << " * " << p1 << " = " << p << "\n";
                        }
                    }

    fout << res << "\n";
    return 0;
}