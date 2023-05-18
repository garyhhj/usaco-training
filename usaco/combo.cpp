/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: combo
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
int validnum(int i, int j, int k, int a, int b, int c, int n) {
    int ad = a + i;
    ad %= n;
    if (ad <= 0) ad = n + ad;

    int bd = b + j;
    bd %= n;
    if (bd <= 0) bd = n + bd;

    int cd = c + k;
    cd %= n;
    if (cd <= 0) cd = n + cd;

    //std::cout << ad << " " << bd << " " << cd << endl; 
    return ad * 1000000 + bd * 1000 + cd;
}

//another approach would be iteratre through all possible combo instead of generating all combo 
int main() {
    ofstream fout("combo.out");
    ifstream fin("combo.in");

    int n, a, b, c, x, y, z;
    fin >> n >> a >> b >> c >> x >> y >> z;

    map<int, bool> mp;
    for (int i = -2; i <= 2; ++i)
        for (int j = -2; j <= 2; ++j)
            for (int k = -2; k <= 2; ++k) {
                int validf = validnum(i, j, k, a, b, c, n);
                int validm = validnum(i, j, k, x, y, z, n);


                mp[validf] = true;
                mp[validm] = true;
            }

    fout << mp.size() << "\n";

    //for (auto i : mp) {
        //std::cout << i.first << endl; 
    //}
    return 0;
}