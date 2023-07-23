#include <iostream>
#include <cmath>
using namespace std;

int arr[1000];
int dp[1000];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = arr[i] + max(dp[i - 3] + arr[i - 1], dp[i - 2]);
    }

    cout << dp[n - 1];

    return 0;
}