#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 1e7

int goal = 0;
int visited[1001][1001];
int tomato[1001][1001];
int day[1001][1001];
// 동서남북
const pair<int, int> DIR[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

void bfs(vector<pair<int, int>> start, int n, int m) {
	queue<pair<int, int>> que;
	for (auto i : start) {
		day[i.first][i.second] = 0;
		que.emplace(i.first, i.second);
	}

	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + DIR[i].second;
			int nx = x + DIR[i].first;

			if (0 < ny and ny <= n and 0 < nx and nx <= m and not visited[ny][nx] and tomato[ny][nx] == 0 and day[y][x] + 1 < day[ny][nx]) {
				goal--;
				visited[ny][nx] = true;
				day[ny][nx] = day[y][x] + 1;
				que.emplace(ny, nx);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// 가로, 세로
	int m, n; cin >> m >> n;

	vector<pair<int, int>> start;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x; cin >> x;
			if (x == 0) goal++;
			else if (x == 1) start.emplace_back(i, j);
			tomato[i][j] = x;
			day[i][j] = INT_MAX;
		}
	}

	bfs(start, n, m);

	// 토마토가 모두 익지 못하는 상황
	if (goal > 0) {
		cout << -1;
		return 0;
	}

	// 토마토가 모두 익을 때까지의 최소 날짜
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (day[i][j] == INT_MAX) continue;
			answer = max(day[i][j], answer);
		}
	}

	cout << answer << '\n';

	return 0;
}