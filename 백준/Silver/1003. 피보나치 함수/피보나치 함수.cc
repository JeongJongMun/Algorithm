#include <bits/stdc++.h>
using namespace std;

int arr[41];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < 41; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        
        if (N == 0) 
            cout << 1 << ' ' << 0 << '\n';
        else 
            cout << arr[N - 1] << ' ' << arr[N] << '\n';

    }

	return 0;
}
