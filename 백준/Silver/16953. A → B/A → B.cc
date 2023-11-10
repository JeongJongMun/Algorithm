#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int A, B, cnt = 1; cin >> A >> B;

	while (B != A) {
		cnt++;
		if (B % 10 == 1) B /= 10;
		else if (B % 2 == 0 and B != 0) B /= 2;
		else {
			cnt = -1;
			break;
		}
	}
	
	cout << cnt;

	return 0;
}