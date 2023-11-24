#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> v(26, -1);
	string str; cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (v[int(str[i]) - 'a'] == -1) v[int(str[i]) - 'a'] = i;
	}

	for (auto i : v) { cout << i << ' '; }
	return 0;
}