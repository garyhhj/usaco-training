/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: milk2
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int n;
    fin >> n;

    vector<int> darr(2000000, 0);

    int maxTime = 0;
    int minTime = 2000000;
    int startIndex, endIndex;
    for (int i = 0; i < n; ++i) {
        fin >> startIndex >> endIndex;
        minTime = min(startIndex, minTime);
        maxTime = max(endIndex, maxTime);
        //endIndex -= 1; 

        darr[startIndex] += 1;
        darr[endIndex] -= 1;
    }

    int currval = 0;
    for (int i = 0; i < darr.size(); ++i) {
        currval += darr[i];
        darr[i] = currval;
    }

    //iterate and count some values 
    bool milk = darr[minTime];
    int currMilk = 0;
    int currRest = 0;
    int currContinuous = 0;
    for (int i = minTime; i < maxTime + 1; ++i) {

        if (milk && !darr[i]) {
            //need to swap to !milk 
            milk = false;
            currMilk = max(currContinuous, currMilk);
            currContinuous = 0;
        }

        if (!milk && darr[i]) {
            //need to swap to milk
            milk = true;
            currRest = max(currContinuous, currRest);
            currContinuous = 0;
        }

        ++currContinuous;
    }

    fout << currMilk << " " << currRest << "\n";

    return 0;
}