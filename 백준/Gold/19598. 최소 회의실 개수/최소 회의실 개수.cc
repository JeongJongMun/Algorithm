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
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> meetings;
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		meetings.emplace(s, e);
	}
	
	auto [a, b] = meetings.top();
	meetings.pop();
	pq.emplace(b);
	int ans = 1;
	
	while (!meetings.empty())
	{
		auto [start, end] = meetings.top();
		meetings.pop();

		while (!pq.empty() and pq.top() <= start)
			pq.pop();

		pq.emplace(end);
		ans = max(ans, (int)pq.size());
	}
	
	cout << ans;
	
	return 0;
}