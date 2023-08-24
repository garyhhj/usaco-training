/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: fracdec
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

int n, d;

ofstream fout("fracdec.out");
ifstream fin("fracdec.in");

int numDigits(int num) {
    int res = 0;
    while (num != 0) {
        num /= 10;
        res += 1;
    }
    return res;
}

void print(const string& str) {
    static int count = 0;
    for (int i = 0; i < str.size(); ++i) {
        fout << str[i];
        count += 1;
        if (count == 76) {
            fout << "\n"; count = 0;
        }
    }
}

int main() {

    fin >> n >> d;

    if (n % d == 0) {
        print(to_string(n / d));
        print(".0");
        print("\n");
        return 0;
    }

    print(to_string(n / d));
    print(".");
    n %= d;

    vector<int> val;
    map<int, int> valPos;

    int rightBracket = -1;
    int leftBracket = -1;
    int currPos = 0;
    while (n != 0) {
        //check if we have a loop 
        if (valPos.find(n) != valPos.end()) {
            rightBracket = currPos - 1;
            leftBracket = valPos[n];
            break;
        }
        valPos[n] = currPos;
        currPos += 1;
        n *= 10;
        val.push_back(n / d);
        n %= d;
    }

    //prints decimals 
    for (int i = 0; i < val.size(); ++i) {
        if (i == leftBracket) print("(");
        print(to_string(val[i]));
        if (i == rightBracket) print(")");
    }
    print("\n");

    return 0;
}
