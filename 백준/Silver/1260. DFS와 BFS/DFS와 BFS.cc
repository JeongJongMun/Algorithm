#include <bits/stdc++.h>
using namespace std;

vector<int> DFS(vector<vector<int>>& graph, int s) {
	vector<bool> visited(graph.size(), false);
	vector<int> answer;
	stack<int> stack({ s });

	while (!stack.empty()) {
		int node = stack.top();
		stack.pop();
		if (!visited[node]) {
			visited[node] = true;
			answer.emplace_back(node);
			for (int i = 0; i < graph[node].size(); i++) {
				stack.push(graph[node][i]);
			}
		}
	}
	return answer;
}


vector<int> BFS(vector<vector<int>>& graph, int s) {
	vector<bool> visited(graph.size(), false);
	vector<int> answer;
	queue<int> queue({ s });

	while (!queue.empty()) {
		int node = queue.front();
		queue.pop();
		if (!visited[node]) {
			visited[node] = true;
			answer.emplace_back(node);
			for (int i = 0; i < graph[node].size(); i++) {
				queue.push(graph[node][i]);
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int v, e, s; cin >> v >> e >> s;
	vector<vector<int>> graph(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= v; i++) sort(graph[i].rbegin(), graph[i].rend());
	vector<int> answer = DFS(graph, s);
	for (auto & i : answer) cout << i << " ";
	cout << "\n";

	for (int i = 1; i <= v; i++) sort(graph[i].begin(), graph[i].end());
	vector<int> answer2 = BFS(graph, s);
	for (auto & i : answer2) cout << i << " ";
	cout << "\n";

	return 0;
}
