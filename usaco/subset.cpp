/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: subset
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

ll totalSum;
ll numSubsetSums = 0;

ll dpState[40 * 41][40]; //sum position  


//there should be some dp here 
ll subsetSums(ll currSum, ll currNum) {

    //base cases
    if (currSum == totalSum) {
        //dpState[totalSum][currNum - 1] = 1; 
        numSubsetSums += 1;
        return 1;
    }

    if (currNum == n + 1) {
        return 0;
    }


    //check dpState   
    if (dpState[currSum][currNum] != -1) {
        numSubsetSums += dpState[currSum][currNum];
        return dpState[currSum][currNum];
    }
    else {

        //recurse to solve if dpState not precalculated 
        ll r = subsetSums(currSum + currNum, currNum + 1);
        ll l = subsetSums(currSum, currNum + 1);
        dpState[currSum][currNum] = r + l;
        return r + l;
    }
}

int main() {
    ofstream fout("subset.out");
    ifstream fin("subset.in");

    memset(dpState, -1, sizeof(dpState));

    fin >> n;
    ll total = n * (n + 1) / 2;
    if (total % 2) {
        fout << 0 << '\n';
    }
    else {
        totalSum = total / 2;
        subsetSums(0, 1);
        fout << numSubsetSums / 2 << '\n';
    }

    return 0;
}

