#include <bits/stdc++.h>
using namespace std;

int graph[501][501];
bool visited[501][501];
int max_area;
int cnt;

vector<pair<int, int>> dir = {
	{1, 0},
	{-1, 0},
	{0, -1},
	{0, 1}
};

int dfs(int y, int x, int area) {
	visited[y][x] = true;
	int nx, ny;
	int size = area;
	for (int i = 0; i < dir.size(); i++) {
		nx = x + dir[i].first;
		ny = y + dir[i].second;
		if (0 <= nx and nx <= 500 and 0 <= ny and ny <= 500 and not visited[ny][nx] and graph[ny][nx]) {
			size += dfs(ny, nx, area);
		}
	}

	return size;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (not visited[i][j] and graph[i][j]) {
				max_area = max(max_area, dfs(i, j, 1));
				cnt++;
			}
		}
	}


cout << cnt << endl << max_area;

return 0;
}