#include<iostream>
#include<algorithm>

using namespace std;
int arr[1000001];
int L[1000001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int temp;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (idx == 0) L[idx++] = temp;
        else {
            if (L[idx - 1] < temp) L[idx++] = temp;
            else {
                L[lower_bound(L, L + idx, temp) - L] = temp;
            }
        }
    }
    cout << idx;
}