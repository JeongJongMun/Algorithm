#include <bits/stdc++.h>
using namespace std;
#define MAX 25

int N;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
priority_queue<int> houses;

struct Point {
	int x;
	int y;
	
	Point(int a, int b) : x(a), y(b) {}
};

int bfs(int i, int j) {
	if (visited[i][j] or arr[i][j] == 0) return 0;
	queue<Point> q;
	q.emplace(i, j);
	visited[i][j] = true;
	int cnt = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[nx][ny] != 0 and !visited[nx][ny] and nx >= 0 and nx < MAX and ny >= 0 and ny < MAX) {
				q.emplace(nx, ny);
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}

	return cnt;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		for (int j = 0; j < str.length(); j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num = bfs(i, j);
			if (num != 0) houses.push(-num);
		}
	}

	cout << houses.size() << '\n';
	while (!houses.empty()) {
		cout << -houses.top() << '\n';
		houses.pop();
	}
	
	return 0;
}