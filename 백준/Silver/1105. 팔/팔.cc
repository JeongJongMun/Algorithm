#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string L, R; cin >> L >> R;
	
	int answer = 0;
	if (L.length() != R.length()) cout << 0;
	else {
		for (int i = 0; i < L.length(); i++) {
			if (L[i] == R[i]) {
				if (L[i] == '8') answer++;
			}
			else break;
		}
		cout << answer;
	}

	return 0;
}