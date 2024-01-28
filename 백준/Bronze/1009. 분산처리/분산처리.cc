#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		int ans = 1;
		for (int j = 0; j < b; j++) {
			ans = (ans * a) % 10;
		}
		if (ans == 0) ans = 10;
		cout << ans << "\n";
	}
	return 0;
}