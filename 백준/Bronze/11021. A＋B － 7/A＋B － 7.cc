#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T; cin >> T;
	int num = 1;
	for (int i = 0; i < T; i++) {
		int a, b; cin >> a >> b;
		cout << "Case #" << num << ": " << a + b << '\n';
		num++;
	}


	return 0;
}