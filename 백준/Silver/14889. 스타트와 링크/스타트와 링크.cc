#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

int N;
int stats[21][21];
bool check[22];
int answer = INT_MAX;

void DFS(int x, int pos) // x: 카운트 수, pos: 다음 값 
{
	if (x == N / 2) {
		int start = 0, link = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[i] && check[j]) start += stats[i][j];
				if (!check[i] && !check[j]) link += stats[i][j];
			}
		}
		int stat_gap = abs(start - link);
		if (answer > stat_gap) answer = stat_gap;

		return;
	}

	for (int i = pos; i < N; i++) {
		check[i] = true;
		DFS(x + 1, i + 1);
		check[i] = false;
	}
}

int main() 
{

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> stats[i][j];
		}
	}

	DFS(0, 1);

	cout << answer;

	return 0;
}