/* Use the slash-star style comments or the system won't see your
   identification information */
   /*
   ID: gary_131
   TASK: castle
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;

const int MAXMN = 50;
int castle[MAXMN + 1][MAXMN + 1];
int visited[MAXMN + 1][MAXMN + 1];
int component[MAXMN + 1][MAXMN + 1];
int componentSize[(MAXMN + 1) * (MAXMN + 1)];

//learn to use stuct with array so don't need to use vector with array which makes coding style look weird 
vector<vector<pair<pair<int, int>, pair<int, int>>>> componentAdj((MAXMN + 1)* (MAXMN + 1));


int col, row;

int numRooms = 0;
int largestRoomSize = -1;
int currRoomSize = 0;

const uint32_t WEST = 0b0001;
const uint32_t NORTH = 0b0010;
const uint32_t EAST = 0b0100;
const uint32_t SOUTH = 0b1000;

void dfs(int row, int col) {

    visited[row][col] = 1;
    currRoomSize += 1;

    int currNodeVal = castle[row][col];
    if ((currNodeVal & NORTH) == 0x0 && !visited[row - 1][col]) {
        dfs(row - 1, col);
    }

    if ((currNodeVal & SOUTH) == 0x0 && !visited[row + 1][col]) {
        dfs(row + 1, col);
    }

    if ((currNodeVal & EAST) == 0x0 && !visited[row][col + 1]) {
        dfs(row, col + 1);
    }

    if ((currNodeVal & WEST) == 0x0 && !visited[row][col - 1]) {
        dfs(row, col - 1);
    }
}

int componentNum = 1;
void labelComponent(int row, int col) {
    visited[row][col] = 1;

    component[row][col] = componentNum;
    int currNodeVal = castle[row][col];
    if ((currNodeVal & NORTH) == 0x0 && !visited[row - 1][col]) {
        labelComponent(row - 1, col);
    }

    if ((currNodeVal & SOUTH) == 0x0 && !visited[row + 1][col]) {
        labelComponent(row + 1, col);
    }

    if ((currNodeVal & EAST) == 0x0 && !visited[row][col + 1]) {
        labelComponent(row, col + 1);
    }

    if ((currNodeVal & WEST) == 0x0 && !visited[row][col - 1]) {
        labelComponent(row, col - 1);
    }
}

bool inRange(int nextRow, int nextCol) {
    if (nextRow < 0 || nextCol < 0) return false;
    if (nextRow > row || nextCol > col) return false;
    return true;
}


void updateConnections(int currRow, int currCol, int nextRow, int nextCol, int direction) {
    int srcCompNum = component[currRow][currCol];
    int desCompNum = component[nextRow][nextCol];
    if (srcCompNum == desCompNum) return;

    componentAdj[srcCompNum].push_back({ {currRow, currCol}, {desCompNum, direction} });
}

void checkConnections(int row, int col) {

    //this is just to denote connections between two components 
    int currNodeVal = castle[row][col];
    if (currNodeVal & NORTH && inRange(row - 1, col)) {
        //there is a wall to the north that we can break... should we update it 
        updateConnections(row, col, row - 1, col, NORTH);
    }

    if (currNodeVal & EAST && inRange(row, col + 1)) {
        updateConnections(row, col, row, col + 1, EAST);
    }


}

int main() {
    ofstream fout("castle.out");
    ifstream fin("castle.in");

    fin >> col >> row;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            fin >> castle[i][j];
        }
    }

    //label components 
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!visited[i][j]) {
                labelComponent(i, j);
                ++componentNum;
            }
        }
    }

    //reset visited 
    for (int i = 0; i <= MAXMN; ++i) {
        std::fill(visited[i], visited[i] + MAXMN + 1, 0);
    }

    //component and their size 
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!visited[i][j]) {
                numRooms += 1;
                dfs(i, j);
                componentSize[component[i][j]] = currRoomSize;
                largestRoomSize = max(largestRoomSize, currRoomSize);
                currRoomSize = 0;
            }
        }
    }

    //reset visited 
    for (int i = 0; i <= MAXMN; ++i) {
        std::fill(visited[i], visited[i] + MAXMN + 1, 0);
    }

    //need to create component and their connections 
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            checkConnections(i, j);
        }
    }

    //pick the most optimal wall 
    int largestCombinedRoomSize = 0;
    int moduleRow = -1;
    int moduleCol = -1;
    int moduleDir = -1;
    for (int i = 0; i < componentAdj.size(); ++i) {
        for (int j = 0; j < componentAdj[i].size(); ++j) {
            pair<pair<int, int>, pair<int, int>>& currConnection = componentAdj[i][j];

            int& srcCompNum = i;
            int desCompNum = currConnection.second.first;
            //now check component size and add them together 
            int combinedRoomSize = componentSize[srcCompNum] + componentSize[desCompNum];

            if (combinedRoomSize > largestCombinedRoomSize) {
                largestCombinedRoomSize = combinedRoomSize;
                moduleRow = currConnection.first.first;
                moduleCol = currConnection.first.second;
                moduleDir = currConnection.second.second;
            }
            else if (combinedRoomSize == largestCombinedRoomSize) {
                //need to check precedence 
                bool update = false;
                if (currConnection.first.second < moduleCol) {
                    update = true;
                }
                else if (currConnection.first.second == moduleCol) {
                    if (currConnection.first.first > moduleRow) {
                        update = true;
                    }
                    else if (currConnection.first.first == moduleRow) {
                        if (currConnection.second.second == NORTH) {
                            update = true;
                        }
                    }
                }


                if (update) {
                    largestCombinedRoomSize = combinedRoomSize;
                    moduleRow = currConnection.first.first;
                    moduleCol = currConnection.first.second;
                    moduleDir = currConnection.second.second;
                }
            }

        }
    }



    fout << numRooms << "\n";
    fout << largestRoomSize << "\n";
    fout << largestCombinedRoomSize << "\n";
    fout << moduleRow + 1 << " " << moduleCol + 1 << " " << (moduleDir == NORTH ? "N" : "E") << "\n";


    return 0;
}
