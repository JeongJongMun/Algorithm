#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	if (s[0] == '0') {
		if (s[1] == 'x') {
			cout << stoul(s, NULL, 16);
		}
		else {
			cout << stoul(s, NULL, 8);
		}
	}
	else {
		cout << s;
	}

	return 0;
}