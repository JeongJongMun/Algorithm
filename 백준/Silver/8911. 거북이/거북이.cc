#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int arr[501];
int t;
string command; 

int dirX[4] = { 1, 0, -1, 0 }; // 동남서북
int dirY[4] = { 0, -1, 0, 1 };


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        int curDir = 3;
        int curX = 0, curY = 0;
        int maxX = 0, minX = 0, maxY = 0, minY = 0;
        cin >> command;

        for (int j = 0; j < command.size(); j++) {
            if (command[j] == 'L') {
                curDir = (curDir + 3) % 4;
            }
            else if (command[j] == 'R') {
                curDir = (curDir + 1) % 4;
            }

            if (command[j] == 'F') {
                curX += dirX[curDir];
                curY += dirY[curDir];
            }
            else if (command[j] == 'B') {
                curX -= dirX[curDir];
                curY -= dirY[curDir];
            }
            maxX = max(curX, maxX);
            minX = min(curX, minX);
            maxY = max(curY, maxY);
            minY = min(curY, minY);
        }
        cout << (maxX - minX) * (maxY - minY) << endl;
    }

    return 0;
}
