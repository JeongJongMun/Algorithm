#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;
	vector<int> v;
	vector<int> answer;

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	int i = 0;
	while (!v.empty()) {
		i = (i + K - 1) % N;
		N--;
		answer.push_back(v[i]);
		v.erase(v.begin() + i);
	}

	cout << '<';
	for (auto i : answer) {
		if (i != answer.back()) cout << i << ", ";
		else cout << i;
	}
	cout << '>';

	return 0;
}