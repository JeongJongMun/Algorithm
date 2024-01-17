#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	priority_queue<int> pq;

	int N; cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x != 0) pq.push(x);
		else {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}