#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a < b;
		else return abs(a) > abs(b);
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	priority_queue<int, vector<int>, cmp> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x; cin >> x;

		if (x != 0) {
			pq.push(-x);
		}
		else {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << -pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}