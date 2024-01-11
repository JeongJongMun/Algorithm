#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int K; cin >> K;
		if (K == 0) break;

		vector<int> lotto(K);

		for (int i = 0; i < K; i++) {
			cin >> lotto[i];
		}

		vector<int> sub;

		for (int i = 0; i < 6; i++) sub.push_back(0);
		for (int i = 0; i < K - 6; i++) sub.push_back(1);


		do {
			for (int i = 0; i < K; i++) {
				if (sub[i] == 0) {
					cout << lotto[i] << ' ';
				}
			}
			cout << '\n';

		} while (next_permutation(sub.begin(), sub.end()));

		cout << '\n';
	}


	
	return 0;
}