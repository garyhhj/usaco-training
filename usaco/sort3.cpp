/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: sort3
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
#include <cmath>

typedef long long ll;
using namespace std;


int n;

int main() {
    ofstream fout("sort3.out");
    ifstream fin("sort3.in");
    fin >> n;

    vector<int> sorted(n);
    vector<int> unsorted;

    for (int i = 0; i < n; ++i) {
        fin >> sorted[i];
    }

    unsorted = sorted;
    sort(sorted.begin(), sorted.end());



    int count = 0;

    //swap elements that will result in both elements being in right place 
    for (int curr = 0; curr < n; ++curr) {
        if (unsorted[curr] == sorted[curr]) continue;

        for (int i = curr + 1; i < n; ++i) {
            if (unsorted[curr] == sorted[i] && sorted[curr] == unsorted[i]) {
                count += 1;
                swap(unsorted[curr], unsorted[i]);
                break;
            }
        }
    }

    //add 2 * number of 1's in wrong place 
    for (int i = 0; i < n; ++i) {
        if (sorted[i] != 1) break;
        if (unsorted[i] != 1 && sorted[i] == 1) count += 2;
    }

    fout << count << "\n";


    return 0;
}
