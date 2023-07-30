#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int x;
    for (int i = 0; i < N + M; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    for (auto i : v) {
        cout << i << " ";
    }

    return 0;
}