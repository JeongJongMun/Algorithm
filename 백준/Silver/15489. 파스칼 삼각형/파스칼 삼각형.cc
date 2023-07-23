#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int r, c, w;
int arr[31][31];
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> w;
    
    for (int i = 0; i < r + w; i++) {
        for (int j = 0; j < r + w; j++) {
            if (!i || !j) arr[i][j] = 1;
            else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }

    for (int i = r - c; i < r - c + w; i++) {
        for (int j = c - 1; (j < c - 1 + w) && (r + w - i - 1 > j); j++) {
            sum += arr[i][j];
        }
    }

    cout << sum;

    return 0;
}