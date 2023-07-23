#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[3][1001];
int dp[3][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
    }

    for (int i = 0; i < n; i++) {
        dp[0][i] = arr[0][i] + min({ dp[0][i - 2] + min(arr[1][i - 1], arr[2][i - 1]), dp[1][i - 1], dp[2][i - 1]});
        dp[1][i] = arr[1][i] + min({ dp[1][i - 2] + min(arr[0][i - 1], arr[2][i - 1]), dp[0][i - 1], dp[2][i - 1]});
        dp[2][i] = arr[2][i] + min({ dp[2][i - 2] + min(arr[0][i - 1], arr[1][i - 1]), dp[0][i - 1], dp[1][i - 1]});
    }

    cout << min({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1] }) << endl;

    return 0;
}
