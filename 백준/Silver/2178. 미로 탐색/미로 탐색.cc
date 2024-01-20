#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[100][100];
int cnt[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.emplace(i, j);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 and nx < n and ny >= 0 and ny < m and graph[nx][ny] != 0 and cnt[nx][ny] == 0) {
				q.emplace(nx, ny);
				cnt[nx][ny] = cnt[x][y] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	cnt[0][0] = 1;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			graph[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0);
	cout << cnt[n - 1][m - 1] << '\n';

	return 0;
}