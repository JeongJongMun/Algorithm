#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define MIN 0

vector<int> dist(MAX + 1);
vector<int> edge[MAX + 1];
bool visited[MAX + 1];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	visited[start] = true;

	while (!q.empty()) {
		int c_node = q.front();
		q.pop();

		for (int i = 0; i < edge[c_node].size(); i++) {
			int n_node = edge[c_node][i];
			if (!visited[n_node]) q.push(n_node);
			visited[n_node] = true;

			if (dist[n_node] > dist[c_node] + 1) {
				dist[n_node] = dist[c_node] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;

	if (N >= K) cout << N - K << '\n';
	else {
		// 에지 생성
		for (int i = 0; i <= MAX; i++) {
			if (i + 1 <= MAX) edge[i].push_back(i + 1);
			if (i - 1 >= MIN) edge[i].push_back(i - 1);
			if (i * 2 <= MAX) edge[i].push_back(i * 2);
		}
		// 거리 초기화
		for (int i = 0; i <= MAX; i++) dist[i] = INT_MAX;

		bfs(N);
		cout << dist[K] << '\n';
	}

	return 0;
}