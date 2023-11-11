#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<pair<int, int>> cow;
	for (int i = 0; i < N; i++) {
		int s, e; cin >> s >> e;
		cow.emplace_back(s, e);
	}

	sort(cow.begin(), cow.end());

	int time = 0;
	for (int i = 0; i < N; i++) {
		if (cow[i].first >= time) time = cow[i].first + cow[i].second;
		else time += cow[i].second;
	}

	cout << time;

	return 0;
}