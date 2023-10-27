#include <bits/stdc++.h>
using namespace std;

int T, N;
int arr[12];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 12; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << arr[N] << '\n';
	}


	return 0;
}