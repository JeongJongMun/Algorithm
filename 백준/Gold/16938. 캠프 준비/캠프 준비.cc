#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    // l <= 문제 난이도의 합 <= r
    // x <= 가장 어려운 문제 - 가장 쉬운 문제 
    int n, l, r, x; cin >> n >> l >> r >> x;
    int s = 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s |= (1 << i);
    }
    int cnt = 0;
    for (int subset = s; subset; subset = (subset - 1) & s) {
        vector<int> v_subset;
        bitset<15UL> b = bitset<15>(subset);
        for (int i = 0; i < 15; i++) {
            if (b[i]) {
                v_subset.push_back(p[i]);
            }
        }
        int sum = accumulate(v_subset.begin(), v_subset.end(), 0);
        int max_elem = *max_element(v_subset.begin(), v_subset.end());
        int min_elem = *min_element(v_subset.begin(), v_subset.end());
        if (l <= sum && sum <= r && max_elem - min_elem >= x) {
            cnt += 1;
        }
    }

    cout << cnt;

    return 0;
}