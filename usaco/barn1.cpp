/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: barn1
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

int main() {
    ofstream fout("barn1.out");
    ifstream fin("barn1.in");

    int m, s, c; //max # of boards, number of stalls, number of cows in stall 
    fin >> m >> s >> c;

    vector<int> stalls(s + 1, 0);

    int firstStall = 2000, lastStall = -2000;
    int stallCow;
    for (int i = 0; i < c; ++i) {
        fin >> stallCow;
        stalls[stallCow] = 1;

        if (stallCow < firstStall) firstStall = stallCow;
        if (stallCow > lastStall) lastStall = stallCow;
    }

    /*
    assume one board then remove largest gaps between stalls to increase board count
    */
    //get gaps between stalls 
    vector<int> gaps;
    int gap = 0;
    for (int i = firstStall; i <= lastStall; ++i) {
        if (stalls[i] == 0) {
            gap += 1;
        }
        else if (stalls[i] == 1 && gap != 0) {
            gaps.push_back(gap);
            gap = 0;
        }
    }

    sort(gaps.rbegin(), gaps.rend());

    int totalNumberOfStallBlocker = lastStall - firstStall + 1;
    int gapsit = 0;
    int boardUsed = 1;
    while (boardUsed < m && gapsit < gaps.size()) {
        totalNumberOfStallBlocker -= gaps[gapsit];
        ++gapsit;
        ++boardUsed;
    }

    fout << totalNumberOfStallBlocker << "\n";
    return 0;
}