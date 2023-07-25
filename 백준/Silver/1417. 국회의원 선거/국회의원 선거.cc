#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    while (1) {
        int cnt = 0;
        int maxI = 0;
        for (int i = 1; i < n; i++) {
            //if (cnt == n - 1) break;

            if (v[maxI] <= v[i]) maxI = i;
            else cnt++;

            //else if (v[0] <= v[i] && v[i] > 0) {

            //}
        }
        if (cnt == n - 1) break;
        if (v[0] <= v[maxI]) {
            answer++;
            v[maxI]--;
            v[0]++;
        }
    }

    cout << answer;

    return 0;
}
/*
3
0
1
5

3
*/