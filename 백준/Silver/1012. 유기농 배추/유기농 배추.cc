#include <bits/stdc++.h>
using namespace std;

bool arr[51][51];
bool isVisited[51][51];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int T, M, N, K;

bool dfs(int y, int x) {
	if (isVisited[y][x]) return false;
	isVisited[y][x] = true;
	
	// 동서남북으로 1칸씩 이동
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		// 배추가 있는 경우 조사
		if (nx >= 0 && ny >= 0 && nx < M && ny < N && arr[ny][nx])
			dfs(ny, nx);
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(arr, false, sizeof(arr));
		memset(isVisited, false, sizeof(isVisited));
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = true;
		}

		int answer = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[j][k] && !isVisited[j][k]) {
					if (dfs(j, k))
						answer++;
				}
			}
		}

		cout << answer << '\n';
	}

	return 0;
}
