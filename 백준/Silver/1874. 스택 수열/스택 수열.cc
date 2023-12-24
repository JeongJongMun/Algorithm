#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;

	stack<int> s;
	vector<char> ans;
	int top = 1;

	for (int i = 0; i < N; i++) {
		int x; cin >> x;

		while (top <= x) {
			s.push(top);
			ans.push_back('+');
			top++;
		}
		if (!s.empty() and s.top() == x) {
			ans.push_back('-');
			s.pop();
		}
		else {
			cout << "NO" << '\n';
			return 0;
		}

	}

	for (auto i : ans) {
		cout << i << '\n';
	}

	return 0;
}