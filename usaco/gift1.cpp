/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: gift1
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");

    map<string, int> nameBalance;
    vector<string> nameOrder;

    int n, amount;
    fin >> n;
    string name;
    while (n--) {
        fin >> name;
        nameBalance[name] = 0;
        nameOrder.push_back(name);
    }

    //name and then two ints 
    while (fin >> name >> amount >> n) {
        nameBalance[name] -= amount;

        if (n != 0) {
            int giftedAmount = amount / n;
            while (n--) {
                string receiver;
                fin >> receiver;
                nameBalance[receiver] += giftedAmount;
                amount -= giftedAmount;
            }
        }

        nameBalance[name] += amount;
    }

    //names need to be printed in same order that is received 
    for (auto i : nameOrder) {
        fout << i << " " << nameBalance[i] << "\n";
    }
    return 0;
}