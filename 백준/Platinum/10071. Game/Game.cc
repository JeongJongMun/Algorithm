#include "game.h"
#include <algorithm>
using namespace std;

int counter[1501];

void initialize(int n) {

}

int hasEdge(int u, int v) {
    int m = max(u, v);
    counter[m]++;

    return counter[m] == m;
}
    