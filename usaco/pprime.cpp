/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: pprime
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

int a, b;

int numDigits(int num) {
    int digits = 0;
    while (num) {
        num /= 10;
        ++digits;
    }
    return digits;
}

vector<int> num(20, 0);
int convertNum(int slots) {
    int res = 0;
    for (int i = 1; i <= slots; ++i) {
        res *= 10;
        res += num[i];
    }
    return res;
}

bool isPrime(int num) {
    //instead of i < sqrt(num), you can use i * i <= n, 
    //have a separate if state for even number since can fileter out even numbers quickly ... hmm but that is just first if statement of loop 
    for (int i = 2; i < sqrt(num) + 1; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

vector<int> res;
void dfs(int slots, int nthDigit) {

    if (nthDigit > slots / 2 + (slots % 2 ? 1 : 0)) {
        if (num[1] == 0) return;

        int palindromeNum = convertNum(slots);
        if (palindromeNum >= a && palindromeNum <= b && isPrime(palindromeNum)) {
            res.push_back(palindromeNum);
        }
        return;
    }


    for (int i = 0; i <= 9; ++i) {
        num[nthDigit] = i;
        num[slots - nthDigit + 1] = i;
        dfs(slots, nthDigit + 1);
    }
}

int main() {
    ofstream fout("pprime.out");
    ifstream fin("pprime.in");


    fin >> a >> b;
    int numDigit = numDigits(b);

    for (int i = 1; i <= numDigit; ++i) {
        dfs(i, 1);
    }


    for (int i = 0; i < res.size(); ++i) {
        fout << res[i] << "\n";
    }

    return 0;
}
