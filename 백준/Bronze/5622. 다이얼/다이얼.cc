#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int arr[30] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };

	string s; cin >> s;
	int ans = 0;

	for (int i = 0; i < s.length(); i++) {
		ans += arr[s[i] - 'A'];
	}

	cout << ans;

	return 0;
}