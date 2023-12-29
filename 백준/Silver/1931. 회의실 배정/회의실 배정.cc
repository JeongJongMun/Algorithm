#include <bits/stdc++.h>
using namespace std;

struct Meeting {
	int end, start;
	Meeting(int s, int e) : start(s), end(e) {}
	Meeting() : start(0), end(0) {}

	bool operator<(const Meeting m) const {
		if (this->end == m.end) return this->start < m.start;
		else return this->end < m.end;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<Meeting> mr;
	for (int i = 0; i < N; i++) {
		int s, e; cin >> s >> e;
		mr.push_back(Meeting(s, e));
	}

	sort(mr.begin(), mr.end());

	int ans = 0;
	int ce = 0;
	for (int i = 0; i < N; i++) {
		if (ce <= mr[i].start) {
			ce = mr[i].end;
			ans++;
		}
	}

	cout << ans;

	return 0;
}