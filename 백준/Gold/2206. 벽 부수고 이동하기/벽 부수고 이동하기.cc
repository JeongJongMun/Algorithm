#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Node
{
	int y;
	int x;
	bool isDestroy;
	Node(int y, int x, bool isDestory) : y(y), x(x), isDestroy(isDestory) {}
};

int N, M;
// graph[y][x][0]: 벽을 부수지 않고 최단 거리, graph[y][x][1]: 벽을 부수고 최단 거리
int graph[1000][1000][2] = {};
int answer = INT_MAX;
queue<Node> que;
int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int startY, int startX)
{
	que.emplace(startY, startX, false);

	while (!que.empty())
	{
		Node node = que.front();
		que.pop();

		if (node.y == N - 1 and node.x == M - 1)
		{
			return graph[N - 1][M - 1][node.isDestroy] + 1;
		}
		
		for (auto dir : DIR)
		{
			int ny = node.y + dir[0];
			int nx = node.x + dir[1];

			if (ny < 0 or ny > N - 1 or nx < 0 or nx > M - 1) continue;

			if (graph[ny][nx][0] == 1)
			{
				if (not node.isDestroy)
				{
					graph[ny][nx][1] = graph[node.y][node.x][0] + 1;
					que.emplace(ny, nx, true);
				}
			}
			else if (graph[ny][nx][0] == 0)
			{
				if (node.isDestroy and graph[ny][nx][node.isDestroy] > 0)
					continue;
				graph[ny][nx][node.isDestroy] = graph[node.y][node.x][node.isDestroy] + 1;
				que.emplace(ny, nx, node.isDestroy);
			}
		}
	}
	
	return -1;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string x; cin >> x;
		for (int j = 0; j < M; j++)
			graph[i][j][0] = x[j] - '0';
	}

	cout <<	bfs(0, 0);

	return 0;
}