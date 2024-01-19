#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

vector<int> mem(100001, -1);

int calc(int N) {

	if (N < 0 || N == 1) return -1;
	if (mem[N] != -1) return mem[N];

	int change5 = calc(N - 5);
	if (change5 == -1) {
		int change2 = calc(N - 2);
		if (change2 != -1) mem[N] = change2 + 1;
	}
	else {
		mem[N] = change5 + 1;
	}

	return mem[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	mem[0] = 0;
	mem[2] = 1;
	mem[5] = 1;

	int change; cin >> change;

	cout << calc(change);

	return 0;
}
