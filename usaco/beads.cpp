/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: beads
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
void decrementIndex(int& index, vector<pair<int, int>>& beads) {
    --index;
    if (index == -1) {
        index = beads.size() - 1;
    }
}

void incrementIndex(int& index, vector<pair<int, int>>& beads) {
    ++index;
    index %= beads.size();
}

int count(vector<pair<int, int>>& beads, int index) {
    //count beads on left 
    int leftIndex = index;
    decrementIndex(leftIndex, beads);
    int leftColor = beads[leftIndex].second;
    int leftBeads = beads[leftIndex].first;
    while (true) {
        decrementIndex(leftIndex, beads);
        if (leftColor == 'w') {
            leftColor = beads[leftIndex].second;
            leftBeads += beads[leftIndex].first;
        }
        else if (beads[leftIndex].second == 'w') {
            leftBeads += beads[leftIndex].first;
        }
        else if (beads[leftIndex].second == leftColor) {
            leftBeads += beads[leftIndex].first;
        }
        else {
            break;
        }
    }
    incrementIndex(leftIndex, beads);

    //count beads on right 
    int rightIndex = index;
    int rightBeads = beads[rightIndex].first;
    int rightColor = beads[rightIndex].second;
    while (true) {
        //increment until different color 
        incrementIndex(rightIndex, beads);
        if (rightIndex == leftIndex) {
            break;
        }

        if (rightColor == 'w') {
            rightColor = beads[rightIndex].second;
            rightBeads += beads[rightIndex].first;
        }
        else if (beads[rightIndex].second == 'w') {
            rightBeads += beads[rightIndex].first;
        }
        else if (beads[rightIndex].second == rightColor) {
            rightBeads += beads[rightIndex].first;
        }
        else {
            break;
        }
    }

    //return the sum 
    return leftBeads + rightBeads;
}

int countend(const string& beads, char c) {
    int count = 0;
    for (int i = beads.size() - 1; i >= 0; --i) {
        if (beads[i] == 'b') ++count;
        else break;
    }
    return count;
}


int main() {
    ofstream fout("beads.out");
    ifstream fin("beads.in");

    int n;
    string beads;
    fin >> n;
    fin >> beads;

    vector<pair<int, int>> bead;
    map<int, int> mp;

    int currColor = -1;
    int currIndex = -1;
    for (int i = 0; i < n; ++i) {
        mp[beads[i]] += 1;
        if (currColor != beads[i]) {
            currColor = beads[i];
            ++currIndex;

            bead.push_back({ 0, 0 });
        }

        bead[currIndex].second = currColor;
        bead[currIndex].first += 1;
    }

    //check if there are different colors 
    if (mp['r'] == 0 || mp['b'] == 0) {
        fout << beads.size() << "\n";
        return 0;
    }

    int res = 0;
    for (int i = 0; i < bead.size(); ++i) {
        res = max(count(bead, i), res);
    }

    fout << res << "\n";

    return 0;
}