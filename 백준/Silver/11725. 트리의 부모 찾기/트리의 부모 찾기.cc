#include <bits/stdc++.h>
using namespace std;

int N;
int parentNumber[100001];
vector<int> graph[100001];

void dfs(int parent) {

	for (int i = 0; i < graph[parent].size(); i++) {
		int child = graph[parent][i];
		if (parentNumber[child] == 0) {
			parentNumber[child] = parent;
			dfs(child);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parentNumber[i] << '\n';
	}

	return 0;
}