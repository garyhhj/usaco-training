/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: spin
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

const int MAXN = 360;
const int inf = 2000000000;

int wedge[MAXN + 1][MAXN + 1]; //second then state(diff array)  

int speed[5];
int numWedge[5];
int start[5][5];
int len[5][5];


int main() {
    ofstream fout("spin.out");
    ifstream fin("spin.in");

    for (int i = 0; i < 5; ++i) {
        fin >> speed[i];
        fin >> numWedge[i];
        for (int j = 0; j < numWedge[i]; ++j) {
            fin >> start[i][j] >> len[i][j];
        }
    }

    //init diff array wedge 
    for (int time = 0; time < 360; ++time) {
        //iterate through each wheel 
        for (int i = 0; i < 5; ++i) {
            int offSet = (time * speed[i]) % 360;
            //iterate through each wedge 
            for (int j = 0; j < numWedge[i]; ++j) {
                int s = (start[i][j] + offSet) % 360;
                for (int l = 0; l <= len[i][j]; ++l) {
                    wedge[time][(s + l) % 360] += 1;
                }
            }
        }
    }


    //check 
    for (int time = 0; time < 360; ++time) {
        for (int i = 0; i < 360; ++i) {
            if (wedge[time][i] == 5) {
                fout << time << endl;
                return 0;
            }
        }
    }

    fout << "none" << endl;
    return 0;
}
