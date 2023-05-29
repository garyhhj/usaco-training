/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: preface
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

int n;

map<char, int> mp;

void addLetter(char one, char five, char ten, int num) {
    if (num % 5) {
        int nnum = num % 5;
        if (nnum <= 3) mp[one] += nnum;
        else mp[one] += 1;
    }

    if (num >= 4 && num <= 8) mp[five] += 1;
    if (num == 9) mp[ten] += 1;
}

int main() {
    ofstream fout("preface.out");
    ifstream fin("preface.in");

    fin >> n;

    /*   I   1     L   50    M  1000
           V   5     C  100
           X  10     D  500*/

    for (int i = 1; i <= n; ++i) {
        //count the number of letters up till n 
        int num = i;
        if (num % 10) {
            addLetter('I', 'V', 'X', num % 10);
        }
        num /= 10;
        if (num % 10) {
            addLetter('X', 'L', 'C', num % 10);
        }
        num /= 10;
        if (num % 10) {
            addLetter('C', 'D', 'M', num % 10);
        }
        num /= 10;
        if (num % 10) {
            mp['M'] += num % 10;
        }
    }

    vector<char> romanNumeralOrder = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
    for (auto i : romanNumeralOrder) {
        if (mp.find(i) != mp.end()) {
            fout << i << " " << mp[i] << "\n";
        }
    }

    return 0;
}

