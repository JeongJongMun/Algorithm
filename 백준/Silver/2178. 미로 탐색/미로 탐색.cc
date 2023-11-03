#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[101][101];
int maze[101][101];
int dist[101][101];

// 동서남북
int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };

int bfs(int a, int b) {
	visited[a][b] = true;

	queue<pair<int, int>> q;
	q.emplace(a, b);

	while (!q.empty()) {
		pair<int, int> top = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = top.first + x[i];
			int ny = top.second + y[i];
			if (!visited[nx][ny] and nx >= 0 and ny >= 0 and nx <= N and ny <= M and maze[nx][ny] == 1) {
				q.emplace(nx, ny);
				visited[nx][ny] = true;
				dist[nx][ny] = dist[top.first][top.second] + 1;
			}
		}
	}

	return dist[N][M];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string a;
		cin >> a;
		for (int j = 1; j <= M; j++) {
			maze[i][j] = a[j - 1] - '0';
		}
	}

	int answer = bfs(1, 1);

	cout << answer + 1;

	return 0;
}