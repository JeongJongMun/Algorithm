#include <bits/stdc++.h>
using namespace std;

struct edge {
	int weight;
	int end;

	edge(int w, int d) : weight(w), end(d) {};

	bool operator<(const edge &e) const {
		return weight > e.weight;
	}
};

vector<edge> graph[300001];

void dijkstra(int v, int e, int start) {
	vector<int> dist(v + 1, INT_MAX);
	vector<bool> visited(v + 1);
	priority_queue<edge> pq;
	pq.emplace(edge(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int node = pq.top().end;
		int distance = pq.top().weight;
		pq.pop();
		visited[node] = true;

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].end;
			int weight = graph[node][i].weight;
			int next_dist = distance + weight;
			if (not visited[next_node] and dist[next_node] > next_dist) {
				pq.emplace(edge(next_dist, next_node));
				dist[next_node] = next_dist;
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INT_MAX) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int v, e; cin >> v >> e;
	int start; cin >> start;

	for (int i = 0; i < e; i++) {
		int s, d, w; cin >> s >> d >> w;
		graph[s].emplace_back(edge(w, d));
	}

	dijkstra(v, e, start);

	return 0;
}