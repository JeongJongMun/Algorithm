#include <iostream>
using namespace std;

int N, answer = 0;
int graph[16][16];

void dfs(int y, int x, int s) // 1 = hori, 2 = verti, 3 = diag
{
	if (y >= N or x >= N) return;

	if (y == N - 1 && x == N - 1)
	{
		answer++;
		return;
	}

	if ((s == 1 or s == 3) and !graph[y][x + 1])
		dfs(y, x + 1, 1);

	if ((s == 2 or s == 3) and !graph[y + 1][x])
		dfs(y + 1, x, 2);

	if (!graph[y + 1][x + 1] and !graph[y + 1][x] and !graph[y][x + 1])
		dfs(y + 1, x + 1, 3);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	int x;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];

	dfs(0, 1, 1);

	cout << answer;

	return 0;
}
