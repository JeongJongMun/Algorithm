#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[101];
vector<int> graph[101];

int bfs(int node) {
	visited[node] = true;
	queue<pair<int, int>> q;
	q.emplace(node, 0);
	int dists = 0;

	while (!q.empty()) {
		pair<int, int> top = q.front();
		int n = top.first;
		int depth = top.second;
		q.pop();

		for (int i = 0; i < graph[n].size(); i++) {
			int next = graph[n][i];
			if (!visited[next]) {
				q.emplace(next, depth+1);
				visited[next] = true;
				dists += depth+1;
			}
		}
	}
	
	return dists;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> answers;
	for (int i = 1; i <= N; i++) {
		answers.push_back(bfs(i));
		memset(visited, false, sizeof(visited));
	}

	cout << min_element(answers.begin(), answers.end()) - answers.begin() + 1;

	return 0;
}