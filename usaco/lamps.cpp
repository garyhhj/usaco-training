/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: lamps
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

int n, c;



vector<int> on;
vector<int> off;
vector<int> buttons(5, 0);

vector<string> res;
vector<map<pair<pair<int, int>, int>, bool>> dpState(10000 + 1, map<pair<pair<int, int>, int>, bool>());


void dfs(int count) {
    if (count == c) {
        string lamps = "";
        for (int i = 1; i <= n; ++i) {
            int curr = 0;
            curr += buttons[1];
            if (i % 2) curr += buttons[2];
            else curr += buttons[3];
            if (i % 3 == 1) curr += buttons[4];

            if (curr % 2) lamps += "0";
            else lamps += "1";
        }


        bool valid = true;

        for (int i = 0; i < on.size(); ++i) {
            if (lamps[on[i] - 1] == '0') {
                valid = false;
                break;
            }
        }

        for (int i = 0; i < off.size(); ++i) {
            if (lamps[off[i] - 1] == '1') {
                valid = false;
                break;
            }
        }

        if (valid) res.push_back(lamps);
        return;
    }

    for (int i = 1; i <= 4; ++i) {

        buttons[i] += 1;
        if (dpState[count].find({ {(buttons[2] + buttons[1]) % 2, (buttons[3] + buttons[1]) % 2}, buttons[4] % 2 }) != dpState[count].end()) {
            buttons[i] -= 1;
            continue;
        }

        dfs(count + 1);
        dpState[count][{ {(buttons[2] + buttons[1]) % 2, (buttons[3] + buttons[1]) % 2}, buttons[4] % 2 }] = 1;
        buttons[i] -= 1;
    }
}




int main() {
    ofstream fout("lamps.out");
    ifstream fin("lamps.in");

    fin >> n >> c;
    //cout << "n c " << n << " " << c << endl; 

    int num;
    while (fin >> num) {
        if (num == -1) break;
        on.push_back(num);
    }

    while (fin >> num) {
        if (num == -1) break;
        off.push_back(num);
    }

    /*  cout << "on: ";
      for (int i = 0; i < on.size(); ++i) {
          cout << on[i] << " ";
      }
      cout << endl;


      cout << "off: ";
      for (int i = 0; i < off.size(); ++i) {
          cout << off[i] << " ";
      }
      cout << endl;*/


    dfs(0);


    //sorts in increasing order 
    auto comp = [](const string& a, const string& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) continue;

            return a[i] < b[i];
        }
        return false;
    };
    sort(res.begin(), res.end(), comp);


    for (int i = 0; i < res.size(); ++i) {
        fout << res[i] << '\n';
    }

    if (res.empty()) {
        fout << "IMPOSSIBLE\n";
    }

    return 0;
}

