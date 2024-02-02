#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	int one = 0, zero = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			one++;
			while (i < s.size() && s[i] == '1') i++;
			i--;
		}
		else {
			zero++;
			while (i < s.size() && s[i] == '0') i++;
			i--;
		}
	}
	cout << (one > zero ? zero : one) << endl;

	return 0;
}