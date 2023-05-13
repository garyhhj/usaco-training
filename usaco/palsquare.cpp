/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: palsquare
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
    ofstream fout("palsquare.out");
    ifstream fin("palsquare.in");

    int b;
    fin >> b;

    vector<pair<string, string>> res;
    for (int n = 1; n <= 300; ++n) {
        int nsquared = n * n;
        //convert nsquared into base b 
        string nsquaredb = baseb(nsquared, b);
        if (isPalindrome(nsquaredb)) {
            res.push_back({ baseb(n, b), nsquaredb });
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        fout << res[i].first << " " << res[i].second << "\n";
    }

    return 0;
}