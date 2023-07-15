#include <iostream>
#include <algorithm>
using namespace std;


int N, M;
int answer[8];
bool isVisited[8];

void DFS(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
			answer[depth] = i;
			DFS(depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	DFS(0);

	return 0;
}