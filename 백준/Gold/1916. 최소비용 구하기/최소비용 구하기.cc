#include <bits/stdc++.h>
using namespace std;


// 도시의 개수(정점), 버스의 개수(간선)
int N, M;

// 시작 도시에서 각 도시까지 최단 거리 저장
vector<int> dists(1001, INT_MAX);

// 버스 정보 (도착 도시, 버스 비용)
vector<pair<int, int>> bus[1001];

void Dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, s);
	dists[s] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dists[cur] < cost)
			continue;

		for (int i = 0; i < bus[cur].size(); i++) {
			int next_node = bus[cur][i].first;
			int next_cost = cost + bus[cur][i].second;

			if (dists[next_node] > next_cost) {
				dists[next_node] = next_cost;
				pq.emplace(-next_cost, next_node);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int start, end, cost; cin >> start >> end >> cost;
		bus[start].emplace_back(end, cost);
	}

	int start, end;
	cin >> start >> end;

	Dijkstra(start);

	cout << dists[end];

	return 0;
}