#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int N; cin >> N;
	int s, e;
	vector<pair<int, int>> m;
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		m.emplace_back(s, e);
	}

	sort(m.begin(), m.end());
	pq.emplace(m[0].second);
	
	int ans = 1;
	for (int i = 1; i < N; i++)
	{
		while (!pq.empty() and pq.top() <= m[i].first)
			pq.pop();

		pq.emplace(m[i].second);
		ans = max(ans, (int)pq.size());
	}
	
	cout << ans;
	
	return 0;
}