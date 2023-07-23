#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[1001][1001];

long long matrix_path(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (!i || !j) arr[i][j] = 1;
            else arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 1000000007;
        }
    }
    return arr[n][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
        }
    }

    cout << matrix_path(n) << " " << n * n << endl;;

    return 0;
}
