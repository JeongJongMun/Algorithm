#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

int n;
int arr[5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    long long sum = LLONG_MAX;
    int answer1, answer2, answer3;
    for (int i = 0; i < n-2; i++) {
        int low = i + 1;
        int high = n - 1;
        while (low != high) {
            long long tempSum = (long long)arr[i] + (long long)arr[low] + (long long)arr[high];
            if (abs(tempSum) < sum) {
                sum = abs(tempSum);
                answer1 = arr[i];
                answer2 = arr[low];
                answer3 = arr[high];
            }
            if (abs(arr[i]) > abs(arr[low] + arr[high]))
                low++;
            else 
                high--;
        }
    }

    cout << answer1 << " " << answer2 << " " << answer3;

    return 0;
}