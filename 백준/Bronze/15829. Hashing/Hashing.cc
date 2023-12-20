#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string str; cin >> str;

	ULL ans = 0;
	ULL modular = 1234567891;
	ULL p = 1;
	for (int i = 0; i < n; i++) {
		if (i != 0) p *= 31;
		p %= modular;
		ans += (str[i] - 'a' + 1) * p;
		ans %= modular;
	}

	cout << ans % modular;

	return 0;
}
/*
50
abcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcde
*/