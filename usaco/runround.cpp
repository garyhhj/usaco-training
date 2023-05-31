/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: runround
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

ll n;

int numDigits(ll number) {
    return int(log10(number) + 1);
}

bool isDigitUnique(ll number) {
    vector<int> freq(10, 0);
    int digitCount = numDigits(number);

    while (digitCount--) {
        int currDigit = number % 10;
        freq[currDigit] += 1;
        number /= 10;
    }

    if (freq[0] != 0) return false;
    for (int i = 1; i < freq.size(); ++i) {
        if (freq[i] != 1 && freq[i] != 0) return false;
    }
    return true;

}


bool isRunAround(ll number) {
    int digitCount = numDigits(number);
    vector<int> freq(digitCount, 0);
    vector<int> num(digitCount);

    for (int i = num.size() - 1; i >= 0; --i) {
        int currDigit = number % 10;
        num[i] = currDigit;
        number /= 10;
    }

    int currIndex = 0;
    while (digitCount--) {
        int nextIndex = (currIndex + num[currIndex]) % num.size();
        if (nextIndex == currIndex) return false;
        currIndex = nextIndex;
        freq[nextIndex] += 1;
    }
    if (currIndex != 0) return false;

    for (int i = 0; i < freq.size(); ++i) {
        if (freq[i] > 1 || freq[i] == 0) return false;
    }
    return true;
}

int main() {
    ofstream fout("runround.out");
    ifstream fin("runround.in");

    fin >> n;

    for (int i = n + 1; true; ++i) {
        if (isDigitUnique(i) && isRunAround(i)) {
            fout << i << '\n';
            break;
        }
    }


    return 0;
}

