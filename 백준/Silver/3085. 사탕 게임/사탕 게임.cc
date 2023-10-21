#include <bits/stdc++.h>
using namespace std;

int N, answer;
char board[51][51];

int MaxCandy() {
	int ans = 0;
	// 행
	for (int i = 0; i < N; i++) {
		map<char, int> cnt;
		for (int j = 0; j < N; j++) {
			if (board[i][j] == board[i][j + 1]) {
				cnt[board[i][j]]++;
				if (cnt[board[i][j]] > ans) ans = cnt[board[i][j]];
			}
			else cnt.clear();
		}
	}
	// 열
	for (int i = 0; i < N; i++) {
		map<char, int> cnt;
		for (int j = 0; j < N; j++) {
			if (board[j][i] == board[j + 1][i]) {
				cnt[board[j][i]]++;
				if (cnt[board[j][i]] > ans) ans = cnt[board[j][i]];
			}
			else cnt.clear();
		}
	}

	return ans + 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	// 행 교환 후 최대 값
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(board[i][j], board[i][j + 1]);
			int temp = MaxCandy();
			if (temp > answer) answer = temp;
			swap(board[i][j], board[i][j + 1]);
		}
	}

	// 열 교환 후 최대 값
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			swap(board[i][j], board[i + 1][j]);
			int temp = MaxCandy();
			if (temp > answer) answer = temp;
			swap(board[i][j], board[i + 1][j]);
		}
	}

	cout << answer;

	return 0;
}

/*
6
CCYYCC
YYCCYY
CCYYCC
YYCCYY
CCYYCC
YYCCYY
3

5
CPZCC
ZYCPZ
CYYPZ
ZPZCC
CCPYY
3
*/