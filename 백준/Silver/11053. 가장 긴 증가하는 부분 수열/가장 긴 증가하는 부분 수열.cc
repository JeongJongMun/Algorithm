#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];
int answer = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                if (dp[i] > answer) answer = dp[i];
            }
        }
    }

    cout << answer;

    return 0;
}