#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string p; cin >> p;

		stack<char> st;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == '(') st.push(p[j]);
			else {
				if (st.empty()) {
					st.push(p[j]);
				}
				else if (st.top() == '(') {
					st.pop();
				}
			}
		}

		if (st.empty()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}