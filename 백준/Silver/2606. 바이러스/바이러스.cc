#include <bits/stdc++.h>
using namespace std;

int N, M, answer = -1;
bool visited[101];
vector<int> graph[101];

void dfs(int node) {
	visited[node] = true;
	answer++;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next]) dfs(next);
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	dfs(1);

	cout << answer;

	return 0;
}