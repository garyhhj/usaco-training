/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: dualpal
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

char getChar(int val) {
    if (val >= 0 && val <= 9) {
        return char('0' + val);
    }
    else {//if (val >= 10) {
        return char('A' + val - 10);
    }
}

string baseb(int num, int base) {
    std::string res;
    while (num) {
        int quotient = num / base;
        int remainder = num - quotient * base;

        res += getChar(remainder);
        num = quotient;
    }

    reverse(res.begin(), res.end());
    return res;
}

bool isPalindrome(const string& str) {
    for (int i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[str.size() - 1 - i]) return false;
    }
    return true;
}

int main() {
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");

    int n, s;
    fin >> n >> s;

    vector<int> res;
    for (int i = s + 1;; ++i) {
        int count = 0;
        for (int base = 2; base <= 10; ++base) {
            if (isPalindrome(baseb(i, base))) {
                ++count;
                if (count == 2) break;
            }
        }

        if (count == 2) {
            res.push_back(i);
            if (res.size() == n) break;
        }
    }

    for (auto i : res) {
        fout << i << "\n";
    }


    return 0;
}