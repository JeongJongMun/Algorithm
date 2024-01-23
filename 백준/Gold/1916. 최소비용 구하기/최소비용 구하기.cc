#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph[1001];

int Dijkstra(int start, int end) {
	vector<int> visited(1001, 0);
	vector<int> dist(1001, INT_MAX);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (node == end) break;

		visited[node] = 1;
		for (int i = 0; i < graph[node].size(); i++) {
			int next_cost = graph[node][i].first;
			int next_node = graph[node][i].second;
			if (dist[next_node] > cost + next_cost and !visited[next_node]) {
				dist[next_node] = cost + next_cost;
				pq.emplace(-dist[next_node], next_node);
			}
		}
	}

	return dist[end];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, e; cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(c, b);
	}
	int start, end; cin >> start >> end;
	cout << Dijkstra(start, end);

	return 0;
}