#include <bits/stdc++.h>
using namespace std;

string fel(int n) {
	string s = to_string(n);
	string front = s.substr(0, s.size() / 2);
	reverse(s.begin(), s.end());
	string back = s.substr(0, s.size() / 2);

	if (front == back) return "yes";
	else return "no";
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true) {
		int x; cin >> x;
		if (x == 0) break;
		cout << fel(x) << '\n';
	}

	return 0;
}