#include <vector>
#include <stack>
#include <iostream>
using namespace std;

enum State
{
	horizontal,
	diagonal,
	vertical,
};

struct Node
{
	int x;
	int y;
	enum State state;

    Node(int x, int y, State state) : x(x), y(y), state(state) {}
};


int N;
bool visit[16];
int graph[16][16];
int answer = 0;
stack<Node> st;

void TryGoVertical(Node node)
{
	int x = node.x;
	int y = node.y;
	State state = node.state;

	if (state == horizontal) return;

	x++;
	if (x < N && graph[x][y] != 1)
	{
		st.push(Node(x, y, vertical));
	}
}

void TryGoDiagonal(Node node)
{
	int x = node.x;
	int y = node.y;
	State state = node.state;

	x++;
	y++;
	if (x < N && y < N &&
		graph[x][y] != 1 &&
		graph[x - 1][y] != 1 &&
		graph[x][y - 1] != 1)
	{
		st.push(Node(x, y, diagonal));
	}
}

void TryGoHorizontal(Node node)
{
	int x = node.x;
	int y = node.y;
	State state = node.state;

	y++;

	if (state == vertical) return;

	if (y < N && graph[x][y] != 1)
	{
		st.push(Node(x, y, horizontal));
	}
}

void dfs(int x, int y, State state)
{
	st.push(Node(x, y, state));

	while (!st.empty())
	{
        Node node = st.top();
        st.pop();


		if (node.x == N - 1 && node.y == N - 1)
		{
			answer++;
			continue;
		}

		switch (node.state)
		{
			case horizontal:
				TryGoHorizontal(node);
				TryGoDiagonal(node);
				break;

			case vertical:
				TryGoVertical(node);
				TryGoDiagonal(node);
				break;

			case diagonal:
				TryGoVertical(node);
				TryGoHorizontal(node);
				TryGoDiagonal(node);
				break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	int x;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	dfs(0, 1, horizontal);

	cout << answer;

	return 0;
}
