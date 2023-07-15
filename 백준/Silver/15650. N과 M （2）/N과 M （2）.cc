#include <iostream>
#include <algorithm>
using namespace std;


int N, M;
int answer[9];
bool isVisited[9];

void DFS(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!isVisited[i] && (i > answer[depth - 1] || depth == 0)) {
			isVisited[i] = true;
			answer[depth] = i;
			DFS(depth + 1);
			isVisited[i] = false;
		}
	}
}
// 1 2 3 4

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	DFS(0);

	return 0;
}