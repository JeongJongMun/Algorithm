#include <bits/stdc++.h>
using namespace std;

struct edge {
	int weight;
	int end;

	edge(int a, int b) : end(a), weight(b) {};

	void print() {
		cout << '(' << weight << ',' << end << ')' << '\n';
	}

	bool operator<(const edge& e) const {
		return weight > e.weight;
	}
};

vector<vector<edge>> graph(801);
bool visited[801];

int dijkstra(int s, int e) {
	memset(visited, 0, sizeof(bool) * 801);
	vector<int> dist(801, 1e8);

	priority_queue<edge> pq;
	pq.emplace(edge(s, 0));
	dist[s] = 0;
	visited[s] = true;

	while (!pq.empty()) {
		int node = pq.top().end;
		int distance = pq.top().weight;
		pq.pop();
		visited[node] = true;

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].end;
			int cost = graph[node][i].weight;
			int next_cost = distance + cost;
			if (dist[next_node] > next_cost and not visited[next_node]) {
				pq.emplace(edge(next_node, next_cost));
				dist[next_node] = next_cost;
			}
		}
	}

	return dist[e];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int v, e; cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(edge(b, c));
		graph[b].emplace_back(edge(a, c));
	}
	int goal_1, goal_2; cin >> goal_1 >> goal_2;

	int ans = min({ 
		dijkstra(1, goal_1) + dijkstra(goal_1, goal_2) + dijkstra(goal_2, v),
		dijkstra(1, goal_2) + dijkstra(goal_2, goal_1) + dijkstra(goal_1, v),
		//dijkstra(1, goal_1) + dijkstra(goal_1, goal_2) + dijkstra(goal_2, goal_1) + dijkstra(goal_1, v),
		//dijkstra(1, goal_2) + dijkstra(goal_2, goal_1) + dijkstra(goal_1, goal_2) + dijkstra(goal_2, v)
		});

	if (ans >= 1e8) cout << -1;
	else cout << ans;
	return 0;
}