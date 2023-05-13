/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: namenum
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/*2: A, B, C     5 : J, K, L    8 : T, U, V
        3 : D, E, F     6 : M, N, O    9 : W, X, Y
        4 : G, H, I     7 : P, R, S*/
void initLetterNum(vector<int>& letterNum) {
    letterNum['A'] = 2;
    letterNum['B'] = 2;
    letterNum['C'] = 2;

    letterNum['D'] = 3;
    letterNum['E'] = 3;
    letterNum['F'] = 3;

    letterNum['G'] = 4;
    letterNum['H'] = 4;
    letterNum['I'] = 4;

    letterNum['J'] = 5;
    letterNum['K'] = 5;
    letterNum['L'] = 5;

    letterNum['M'] = 6;
    letterNum['N'] = 6;
    letterNum['O'] = 6;

    letterNum['P'] = 7;
    letterNum['R'] = 7;
    letterNum['S'] = 7;

    letterNum['T'] = 8;
    letterNum['U'] = 8;
    letterNum['V'] = 8;

    letterNum['W'] = 9;
    letterNum['X'] = 9;
    letterNum['Y'] = 9;
}

bool validname(long long num, const string& name, const vector<int>& letterNum) {
    long long nameNum = 0;
    for (int i = 0; i < name.size(); ++i) {
        nameNum *= 10;
        nameNum += letterNum[name[i]];
    }
    return num == nameNum;
}


int main() {
    ofstream fout("namenum.out");
    ifstream fin("namenum.in");

    long long num;
    fin >> num;

    vector<int> letterNum(256, 0);
    initLetterNum(letterNum);


    ifstream namein("dict.txt");
    vector<string> validnames;
    string name;
    while (namein >> name) {
        if (validname(num, name, letterNum)) {
            validnames.push_back(name);
        }
    }

    if (validnames.empty()) {
        fout << "NONE" << "\n";
    }
    else {
        for (int i = 0; i < validnames.size(); ++i) {
            fout << validnames[i] << "\n";
        }
    }

    return 0;
}