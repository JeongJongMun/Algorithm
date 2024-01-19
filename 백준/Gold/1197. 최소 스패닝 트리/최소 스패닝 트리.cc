#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int v, e; cin >> v >> e;
	vector<vector<pair<int, int>>> graph(v + 1);
	vector<bool> visited(v + 1, false);
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, 1);
	int ans = 0;

	for (int i = 0; i < e; i++) {
		int s, e, w; cin >> s >> e >> w;
		graph[s].emplace_back(-w, e);
		graph[e].emplace_back(-w, s);
	}

	while (!pq.empty()) {
		int w = -pq.top().first;
		int n = pq.top().second;
		pq.pop();

		if (visited[n] == false) {
			visited[n] = true;
			ans += w;
			for (int i = 0; i < graph[n].size(); i++) pq.emplace(graph[n][i].first, graph[n][i].second);
		}
	}
	cout << ans;

	return 0;
}
