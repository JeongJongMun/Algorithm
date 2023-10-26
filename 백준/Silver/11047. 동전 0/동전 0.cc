#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	int answer = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		if (K == 0) break;
		while (K >= A[i]) {
			answer += K / A[i];
			K %= A[i];
		}
	}

	cout << answer;

	return 0;
}