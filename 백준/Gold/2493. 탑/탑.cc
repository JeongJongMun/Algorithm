#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> tower(n);
	vector<int> ans(n, 0);
	stack<int> s;

	for (int i = 0; i < n; i++) cin >> tower[i];

	for (int i = 0; i < n; i++) {
		while (!s.empty()) {
			if (tower[s.top()] > tower[i]) {
				ans[i] = s.top() + 1;
				break;
			}
			s.pop();
		}
		s.push(i);
	}
	
	for (auto i : ans) cout << i << " ";

	return 0;
}