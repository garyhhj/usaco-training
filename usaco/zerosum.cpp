/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: zerosum
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

int n;

int dp[10];
const int PLUS = 1;
const int MINUS = 2;
const int SPACE = 3;

int getValBefore(int currIndex) {
    int res = 0;
    for (int i = 1; i <= currIndex; ++i) {
        res *= 10;
        res += i;
    }
    return res;
}

int getValAfter(int currIndex) {
    int res = 0;
    int i = currIndex + 1;
    for (; i <= n && dp[i] == SPACE; ++i) {
        res *= 10;
        res += i;
    }
    res *= 10;
    res += i;
    return res;
}

bool zeroSum() {
    int prev = -100;
    for (int i = 1; i <= n; ++i) {
        //I just need to check if it is plus or minus 
        //if it is plus or minus, I need to go check the number before and after the + - symbol 
        //and then figure out the previous number 
        //the number before the symbol 

        //another is if i hit the end then I also need to check gagainst the before 
        if (dp[i] == PLUS || dp[i] == MINUS) {
            //i need to check values before and after 
            if (prev == -100) {
                prev = getValBefore(i);
            }

            int valAfter = getValAfter(i);


            if (dp[i] == PLUS) prev += valAfter;
            if (dp[i] == MINUS) prev -= valAfter;


        }
    }

    return prev == 0;
}

vector<string> res;
void solve(int curr) {
    if (curr == n) {

        if (zeroSum()) {
            string temp = "";
            for (int i = 1; i <= n; ++i) {
                temp += char('0' + i);
                if (dp[i] == PLUS) temp += '+';
                else if (dp[i] == MINUS) temp += '-';
                else if (dp[i] == SPACE) temp += ' ';
            }
            res.push_back(temp);
        }
        return;
    }

    dp[curr] = PLUS;
    solve(curr + 1);
    dp[curr] = MINUS;
    solve(curr + 1);
    dp[curr] = SPACE;
    solve(curr + 1);
}


int main() {
    ofstream fout("zerosum.out");
    ifstream fin("zerosum.in");

    fin >> n;
    solve(1);


    sort(res.begin(), res.end());
    for (auto i : res) {
        fout << i << "\n";
    }

    return 0;
}

