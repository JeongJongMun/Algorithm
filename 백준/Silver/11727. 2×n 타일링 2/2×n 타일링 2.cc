#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	vector<int> arr(N + 1);

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= N; i++) {
		arr[i] = (arr[i - 1] + (arr[i - 2] * 2)) % 10007;
	}

	cout << arr[N];

	return 0;
}