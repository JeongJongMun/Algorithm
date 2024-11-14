#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool solvedDay[1000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, d, w; cin >> N;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> d >> w;
		pq.emplace(w, d);
	}

	int answer = 0;
	while (!pq.empty())
	{
		auto [score, day] = pq.top(); pq.pop();
		for (int i = day; i > 0; i--)
		{
			if (!solvedDay[i - 1])
			{
				solvedDay[i - 1] = true;
				answer += score;
				break;
			}
		}
	}
	
	cout << answer << '\n';
	
	return 0;
}