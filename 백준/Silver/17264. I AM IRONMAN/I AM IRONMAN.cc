#include <bits/stdc++.h>
using namespace std;

int N, P;
int W, L, G;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> P >> W >> L >> G;

	map<string, bool> players;

	string name; char WL;
	for (int i = 0; i < P; i++) {
		cin >> name >> WL;
		players[name] = (WL == 'W');
	}
	
	int score = 0;
	for (int i = 0; i < N; i++) {
		if (score >= G) {
			cout << "I AM NOT IRONMAN!!";
			return 0;
		}

		cin >> name;
		if (players[name]) {
			score += W;
		}
		else score -= L;

		if (score < 0) score = 0;
	}

	cout << "I AM IRONMAN!!";

	return 0;
}