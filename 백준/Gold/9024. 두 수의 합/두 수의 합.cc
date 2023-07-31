#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int T; // 테스트 케이스
int N, K; // 집합의 원소 개수, 찾고자하는 K
int arr[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N >> K;

        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }

        sort(arr, arr + N);

        // 1. K에 가장 가까운 두 수의 합 X를 찾는다.
        // 2. 두 수의 합이 X가 되는 것들을 찾는다.
        // 3. 예를 들어 K가 4라고 하고, 3과 5가 K에 가장 가까운 두 수의 합이라고 할 수 있다.
        // 4. O(3N)에 가능

        int low = 0;
        int high = N - 1;
        int tempAnswer = INT_MAX;
        int tempK;

        while (low != high) {
            if (abs(arr[low] + arr[high] - K) < tempAnswer) {
                tempAnswer = abs(arr[low] + arr[high] - K);
                tempK = arr[low] + arr[high];
            }

            if (arr[low] + arr[high] < K)
                low++;
            else high--;
        }


        low = 0;
        high = N - 1;
        int answer = 0;
        while (low != high) {
            if (arr[low] + arr[high] == tempK) {
                answer++;
            }

            if (arr[low] + arr[high] < tempK)
                low++;
            else high--;
        }
        
        if (tempK < K) {
            tempK = tempK + (K - tempK) + (K - tempK);
        }
        else if (tempK > K) {
            tempK = tempK - (tempK - K) - (tempK - K);
        }
        else {
            cout << answer << endl;
            continue;
        }

        low = 0;
        high = N - 1;
        while (low != high) {
            if (arr[low] + arr[high] == tempK) {
                answer++;
            }

            if (arr[low] + arr[high] < tempK)
                low++;
            else high--;
        }

        cout << answer << endl;

    }


    return 0;
}
/*
1
10 4
 -7 -4 -3 -2 0 1 2 5 9 12
 K에 가장 가까운 수인 X는 5 또는 3, 
 {-7, 12}, {9, -4}, {5, -2}, {5, 0}, {1, 2}
*/