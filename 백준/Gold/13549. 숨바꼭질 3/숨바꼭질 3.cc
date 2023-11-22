#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define MIN 0

struct Node {
	int cost;
	int end;

	// 생성자
	Node(int c, int e) : cost(c), end(e) {}

	// 비용이 작은 순으로 정렬
	bool operator<(const Node n) const {
		return this->cost > n.cost;
	}
};

// 수빈이의 위치 N, 동생의 위치 K
int N, K;

vector<int> dists(100001, INT_MAX);

vector<Node> edges[100001];

void Dijkstra(int s) {
	priority_queue<Node> pq;
	pq.emplace(0, s);
	dists[s] = 0;

	while (!pq.empty()) {
		int cost = pq.top().cost;
		int cur_node = pq.top().end;
		pq.pop();

		for (int i = 0; i < edges[cur_node].size(); i++) {
			int next_cost = cost + edges[cur_node][i].cost;
			int next_node = edges[cur_node][i].end;

			if (dists[next_node] > next_cost) {
				dists[next_node] = next_cost;
				pq.emplace(next_cost, next_node);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;


	if (N <= K) {
		// edge 생성
		for (int i = 0; i <= MAX; i++) {
			if (i + 1 <= MAX) edges[i].emplace_back(1, i + 1);
			if (i - 1 >= MIN) edges[i].emplace_back(1, i - 1);
			if (2 * i <= MAX) edges[i].emplace_back(0, 2 * i);
		}
		Dijkstra(N);
		cout << dists[K];
	}
	else {
		cout << N - K;
	}
	
	return 0;
}