#include <bits/stdc++.h>
using namespace std;

int N;
int temp[3];
int previous[3];
int mini[3];
int maxi[3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;


	for (int i = 1; i <= N; i++) {
		cin >> temp[0] >> temp[1] >> temp[2];
		previous[0] = maxi[0]; previous[1] = maxi[1]; previous[2] = maxi[2];
		maxi[0] = temp[0] + max(previous[0], previous[1]);
		maxi[1] = temp[1] + max({ previous[0], previous[1], previous[2] });
		maxi[2] = temp[2] + max(previous[1], previous[2]);

		previous[0] = mini[0]; previous[1] = mini[1]; previous[2] = mini[2];
		mini[0] = temp[0] + min(previous[0], previous[1]);
		mini[1] = temp[1] + min({ previous[0], previous[1], previous[2] });
		mini[2] = temp[2] + min(previous[1], previous[2]);
	}

	cout << max({ maxi[0], maxi[1], maxi[2] }) << ' ' << min({ mini[0], mini[1], mini[2] });

	return 0;
}