#include <iostream>
#include <queue>
using namespace std;

int G;
priority_queue<int, vector<int>, greater<int>> answer;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> G;

	for (int low = 1, high = 1; ;) {
		if (high * high - low * low > G && high - low == 1) break;
		if (high * high - low * low == G) answer.push(high);
		if (high * high - low * low > G) low++;
		else high++;
	}

	if (answer.empty()) cout << -1;

	while (!answer.empty()) {
		cout << answer.top() << '\n';
		answer.pop();
	}
	
	return 0;
}