/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: milk3
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

int a, b, c;
int aState, bState, cState;

vector<int> res;
map<pair<int, pair<int, int>>, bool> visited;

//pour 1 into 2 
void pour(int& state1, int& state2, int& cap1, int& cap2) {
    int poured = min(state1, cap2 - state2);

    state1 -= poured;
    state2 += poured;
}

void restoreState(int prevaState, int prevbState, int prevcState) {
    aState = prevaState;
    bState = prevbState;
    cState = prevcState;
}

void dfs() {

    //check if state is already visited 
    if (visited.find({ aState, {bState, cState} }) != visited.end()) {
        return;
    }
    else {
        visited[{aState, { bState, cState }}] = true;
    }

    if (aState == 0) {
        res.push_back(cState);
    }
    int curraState = aState;
    int currbState = bState;
    int currcState = cState;

    //this can be done using two for loops instead to make code cleaner 
    if (aState != 0) {
        //pour a into b and c
        pour(aState, bState, a, b);
        dfs();
        restoreState(curraState, currbState, currcState);
        pour(aState, cState, a, c);
        dfs();
        restoreState(curraState, currbState, currcState);
    }

    if (bState != 0) {
        //pour b into a and c 
        pour(bState, aState, b, a);
        dfs();
        restoreState(curraState, currbState, currcState);
        pour(bState, cState, b, c);
        dfs();
        restoreState(curraState, currbState, currcState);
    }

    if (cState != 0) {
        //pour c into a and b 
        pour(cState, aState, c, a);
        dfs();
        restoreState(curraState, currbState, currcState);
        pour(cState, bState, c, b);
        dfs();
        restoreState(curraState, currbState, currcState);
    }
}

int main() {
    ofstream fout("milk3.out");
    ifstream fin("milk3.in");

    fin >> a >> b >> c;
    aState = bState = 0;
    cState = c;

    dfs();

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        fout << res[i];
        if (i != res.size() - 1) fout << " ";
    }
    fout << "\n";

    return 0;
}
