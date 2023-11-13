#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int K; cin >> K;

	int choco_size = 1;
	int cnt = 0;

	while (choco_size < K) {
		choco_size *= 2;
	}
	int choco = choco_size;
	while (choco > 1 and K > 0) {
		if (K >= choco) {
			K -= choco;
		}
		else {
			choco /= 2;
			cnt++;
		}
	}

	cout << choco_size << " " << cnt;

	return 0;
}
