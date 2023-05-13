/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: friday
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void incrementDay(int& day, int daysPassed) {
    day += daysPassed;
    day %= 7;
}

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    vector<int> day13(7, 0);

    bool leapYear = false;
    int day = 0; //monday 
    int numYear;
    fin >> numYear;
    for (int year = 1; year <= numYear; ++year) {
        //update leapYear 
        int currYear = 1900 + year - 1;
        if (currYear % 100 == 0) {
            if (currYear % 400 == 0) {
                leapYear = true;
            }
            else {
                leapYear = false;
            }
        }
        else if (currYear % 4 == 0) {
            leapYear = true;
        }
        else {
            leapYear = false;
        }

        //jan - 31 days 
        incrementDay(day, 12); //jan 13th; 
        ++day13[day];
        incrementDay(day, 31 - 13 + 1); //feb 1st 

        //feb - 28 (29 in leapYear) 
        incrementDay(day, 12); //feb 13th; 
        ++day13[day];
        incrementDay(day, (leapYear ? 29 : 28) - 13 + 1); //march 1st 

        //mar - 31 
        incrementDay(day, 12); //mar 13th; 
        ++day13[day];
        incrementDay(day, 31 - 13 + 1);

        //april - 30 
        incrementDay(day, 12);
        ++day13[day];
        incrementDay(day, 30 - 13 + 1);

        //may - 31 
        incrementDay(day, 12);
        ++day13[day];
        incrementDay(day, 31 - 13 + 1);

        //june - 30 
        incrementDay(day, 12);
        ++day13[day];
        incrementDay(day, 30 - 13 + 1);

        //july - 31
        incrementDay(day, 12);
        ++day13[day];
        incrementDay(day, 31 - 13 + 1);

        //August - 31 
        incrementDay(day, 12);
        ++day13[day];
        incrementDay(day, 31 - 13 + 1);

        //September - 30
        incrementDay(day, 12);
        ++day13[day];
        incrementDay(day, 30 - 13 + 1);

        //October - 31
        incrementDay(day, 12);
        ++day13[day];
        incrementDay(day, 31 - 13 + 1);

        //November - 30 
        incrementDay(day, 12);
        ++day13[day];
        incrementDay(day, 30 - 13 + 1);

        //December - 31
        incrementDay(day, 12);
        ++day13[day];
        incrementDay(day, 31 - 13 + 1);
    }

    //output result , saturday, sunday, ... etc 
    for (int i = 0; i < day13.size(); ++i) {
        fout << day13[(i + 5) % 7];
        if (i < day13.size() - 1) {
            fout << " ";
        }
    }
    fout << "\n";

    return 0;
}