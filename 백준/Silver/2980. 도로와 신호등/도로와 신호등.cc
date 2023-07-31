#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <vector>
using namespace std;

int N; // 신호등의 개수
int L; // 도로의 길이
int D, R, G; // 신호등의 위치, 빨간색/초록색이 지속되는 시간
int arr[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    int answer = 0;
    for (int i = 1; i < N+1; i++) {
        cin >> D >> R >> G;
        arr[i] = D;
        int gap = arr[i] - arr[i - 1];
        int status = (answer + gap) % (R + G);
        // 신호등에 도착했을때 빨간불
        if (status < R) {
            answer += (gap + (R - ((answer + gap) % (R + G))));
        }
        // 신호등에 도착했을때 초록불
        else {
            answer += gap;
        }
    }

    // 신호등을 모두 건너고 나머지 거리를 이동
    answer += L - arr[N];

    cout << answer;

    return 0;
}
/*
4 30
7 13 5
14 4 4
15 3 10
25 1 1

        if (status == 0 ||
            (status < R + G && status > R)) {
            answer += gap;
        }
*/