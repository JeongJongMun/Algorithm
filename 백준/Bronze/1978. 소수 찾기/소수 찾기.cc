#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	int N; cin >> N;
	vector<int> v(N);

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int flag = 0;
		cin >> v[i];
		for (int j = 2; j <= sqrt(v[i]); j++) {
			if (v[i] % j == 0) {
				flag = 1;
				continue;
			}
		}
		if (!flag && v[i] != 1) answer++;
	}

	cout << answer;
	return 0;
}