#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int s, int e) {
	if (n > 1) hanoi(n - 1, s, 6 - s - e);
	cout << s << ' ' << e << '\n';
	if (n > 1) hanoi(n - 1, 6 - s - e, e);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	string a = to_string(pow(2, n));

	int idx = a.find('.');
	a = a.substr(0, idx);
	a[a.length() - 1] -= 1;

	cout << a << '\n';

	if (n <= 20) hanoi(n, 1, 3);

	return 0;
}