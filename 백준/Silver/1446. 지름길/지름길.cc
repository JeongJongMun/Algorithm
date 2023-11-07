#include <bits/stdc++.h>
using namespace std;

// 지금길의 개수, 고속도로의 길이
int N, D;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> D;

	// 목적지까지 최단 거리 저장 배열. INF로 초기화
	vector<int> dists(D + 1, INT_MAX);
	vector<pair<int, int>> graph[10001];

	for (int i = 0; i < N; i++) {
		// 지름길의 시작 위치/도착 위치/길이
		int s, e, l; cin >> s >> e >> l;
		graph[e].emplace_back(s, l);
	}

	// 다익스트라
	dists[0] = 0;
	for (int i = 1; i <= D; i++) {
		if (graph[i].size() == 0) dists[i] = dists[i - 1] + 1;
		else {
			for (auto n : graph[i])
				dists[i] = min(dists[i], min(dists[i - 1] + 1, dists[n.first] + n.second));
		}
	}

	cout << dists[D];

	return 0;
}