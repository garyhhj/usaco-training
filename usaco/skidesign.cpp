/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: skidesign
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

const int MAXN = 1000;

int height[MAXN + 1];
int n;

int main() {
    ofstream fout("skidesign.out");
    ifstream fin("skidesign.in");

    fin >> n;

    for (int i = 1; i <= n; ++i) {
        fin >> height[i];
    }

    sort(height + 1, height + n + 1);
    int lowest = height[1];
    int highest = height[n];

    int res = 0x1 << 30;
    for (int i = lowest; i <= highest - 17; ++i) {
        int lowerBound = i;
        int upperBound = i + 17;

        int sum = 0;
        //iterate through the hills and make sure all hills are going to be at lowerbound or upperbound and add costs 
        for (int heightIndex = 1; heightIndex <= n; ++heightIndex) {
            if (height[heightIndex] < lowerBound) {
                sum += (lowerBound - height[heightIndex]) * (lowerBound - height[heightIndex]);
            }
            else if (height[heightIndex] > upperBound) {
                sum += (upperBound - height[heightIndex]) * (upperBound - height[heightIndex]);
            }
        }

        res = min(res, sum);
    }

    fout << res << "\n";
    return 0;
}
