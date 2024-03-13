#include <bits/stdc++.h>
using namespace std;

int graph[501][501];
int max_area;
int cnt;

vector<pair<int, int>> dir = {
	{1, 0},
	{-1, 0},
	{0, -1},
	{0, 1}
};

int dfs(int y, int x) {
	graph[y][x] = 0;
	int nx, ny;
	int area = 1;
	for (int i = 0; i < dir.size(); i++) {
		nx = x + dir[i].first;
		ny = y + dir[i].second;
		if (0 <= nx and nx <= 500 and 0 <= ny and ny <= 500 and graph[ny][nx])
			area += dfs(ny, nx);
	}
	return area;
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
			if (graph[i][j]) {
				max_area = max(max_area, dfs(i, j));
				cnt++;
			}
		}
	}

	cout << cnt << endl << max_area;

	return 0;
}