#include <bits/stdc++.h>
using namespace std;

int N;
int rooms[50][50];
int dists[50][50];

int dx[4] = { 1, -1, 0 , 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int i, int j) {
	queue<pair<int, int>> q;
	q.emplace(i, j);
	dists[i][j] = 0;

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ni = i + dx[k];
			int nj = j + dy[k];
			if (ni < 0 or nj < 0 or ni >= N or nj >= N) continue;

			if (rooms[ni][nj] and dists[ni][nj] > dists[i][j]) {
				dists[ni][nj] = dists[i][j];
				q.emplace(ni, nj);
			}
			else if (dists[ni][nj] > dists[i][j] + 1) {
				dists[ni][nj] = dists[i][j] + 1;
				q.emplace(ni, nj);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fill(dists[0], dists[50], INT_MAX);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			rooms[i][j] = s[j] - '0';
		}
	}
	dfs(0, 0);

	cout << dists[N - 1][N - 1];

	return 0;
}