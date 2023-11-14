#include <bits/stdc++.h>
using namespace std;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

bool visited[601][601];
int campus[601][601];
int N, M, people;

void dfs(int i, int j) {
	visited[i][j] = true;
	people += campus[i][j];

	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (!visited[ni][nj] and ni >= 0 and ni < N and nj >= 0 and nj < M) {
			dfs(ni, nj);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int si, sj;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'O') {
				continue;
			}
			else if (s[j] == 'X') {
				visited[i][j] = true;
			}
			else if (s[j] == 'I') {
				si = i;
				sj = j;
			}
			else if (s[j] == 'P') {
				campus[i][j] = 1;
			}
		}
	}

	dfs(si, sj);

	if (!people) cout << "TT";
	else cout << people;

	return 0;
}