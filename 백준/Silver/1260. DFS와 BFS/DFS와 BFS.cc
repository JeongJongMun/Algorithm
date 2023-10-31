#include <bits/stdc++.h>
using namespace std;

int N, M, V;
bool visited[1001];
vector<int> graph[1001];

void dfs(int node) {
	visited[node] = true;
	cout << node << ' ';
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next]) dfs(next);
	}
}

void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> V;
	
	int a, b;
	for (int i = 0; i < M; i++) {
		 cin >> a >> b;
		 graph[a].push_back(b);
		 graph[b].push_back(a);
	}
	for (int i = 0; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	memset(visited, false, sizeof(visited));
	cout << '\n';
	bfs(V);

	return 0;
}