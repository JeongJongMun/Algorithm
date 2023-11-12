#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N; cin >> N;
	int cnt = 0;

	string s; cin >> s;
	for (int i = 0; i < N; i++) {
		cnt += s[i] - '0';
	}

	cout << cnt;

	return 0;
}