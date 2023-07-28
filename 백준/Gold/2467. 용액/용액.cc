#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

int n;
int arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int hi = n - 1;
    int low = 0;
    int answer = INT_MAX;
    int answerA, answerB;
    for (int i = 0; i < n; i++) {
        if (hi == low) break;
        if (abs(arr[low] + arr[hi]) < answer) {
            answer = abs(arr[low] + arr[hi]);
            answerA = arr[low];
            answerB = arr[hi];
        }
        if (abs(arr[low]) > abs(arr[hi])) low++;
        else hi--;
    }

    cout << answerA << " " << answerB;

    return 0;
}

/*
9
-1000000 -99 99 100 101 102 103 104 105


*/