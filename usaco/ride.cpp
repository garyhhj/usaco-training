/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: ride
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string comet, group;
    fin >> comet >> group;

    int cometRes = 1, groupRes = 1;
    for (auto i : comet) {
        cometRes *= (i - 'A' + 1);
    }
    cometRes %= 47;

    for (auto i : group) {
        groupRes *= (i - 'A' + 1);
    }
    groupRes %= 47;

    fout << (cometRes == groupRes ? "GO" : "STAY") << "\n";
    return 0;
}