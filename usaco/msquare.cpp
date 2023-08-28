/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: msquare
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

const int inf = 2000000000;

/*
 1 2 3 4
 8 7 6 5
 -> 1234 5678

 A:
 8 7 6 5
 1 2 3 4
 -> 8765 4321

 B:
 4 1 2 3
 5 8 7 6
 -> 4123 6785

 C:
 1 7 2 4
 8 6 3 5
 -> 1724 5368
*/

int nextStateA(int currState) {
    int nextState = 0;
    while (currState) {
        nextState *= 10;
        nextState += currState % 10;
        currState /= 10;
    }
    return nextState;
}

int nextStateB(int currState) {
    int topHalf = currState / 10000;
    int bottomHalf = currState % 10000;

    int _topHalf = (topHalf / 10) + (topHalf % 10) * 1000;
    int _bottomHalf = (bottomHalf % 1000) * 10 + (bottomHalf / 1000) % 10;
    return _topHalf * 10000 + _bottomHalf;
}

int nextStateC(int currState) {
    int topHalf = currState / 10000;
    int bottomHalf = currState % 10000;

    int _topHalf = (topHalf / 1000) * 1000 + ((bottomHalf / 10) % 10) * 100 + ((topHalf / 100) % 10) * 10 + topHalf % 10;
    int _bottomHalf = (bottomHalf / 1000) * 1000 + ((topHalf / 10) % 10) * 100 + ((bottomHalf / 100) % 10) * 10 + bottomHalf % 10;
    return _topHalf * 10000 + _bottomHalf;
}


int main() {
    ofstream fout("msquare.out");
    ifstream fin("msquare.in");

    int temp;
    int target = 0;
    for (int i = 0; i < 8; ++i) {
        fin >> temp;
        target *= 10;
        target += temp;
    }

    priority_queue < pair<int, pair<int, string>>,
        vector<pair<int, pair<int, string>>>, greater<pair<int, pair<int, string>>>> pq;
    map<int, bool> visited;
    pq.push({ 0, {12345678, ""} });
    while (!pq.empty()) {
        int priority = pq.top().first;
        int currState = pq.top().second.first;
        string seq = pq.top().second.second;
        pq.pop();


        //reached target state 
        if (currState == target) {
            fout << priority << endl;
            int count = 0;
            for (int i = 0; i < seq.size(); ++i) {
                count += 1;
                fout << seq[i];
                if (count == 60) fout << "\n";
            }
            fout << endl;
            break;
        }

        //already visited 
        if (visited.find(currState) != visited.end()) continue;
        visited[currState] = true;

        //go to next state  
        //c
        int nextC = nextStateC(currState);
        if (visited.find(nextC) == visited.end()) {
            pq.push({ priority + 1, {nextStateC(currState), seq + "C"} });
        }

        //b
        int nextB = nextStateB(currState);
        if (visited.find(nextB) == visited.end()) {
            pq.push({ priority + 1, {nextStateB(currState), seq + "B"} });
        }

        //a
        int nextA = nextStateA(currState);
        if (visited.find(nextA) == visited.end()) {
            pq.push({ priority + 1, {nextStateA(currState), seq + "A"} });
        }

    }

    return 0;
}
