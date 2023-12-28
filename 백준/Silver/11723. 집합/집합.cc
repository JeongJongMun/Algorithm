#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	set<int> s;
	string command; int x;
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == "add") {
			cin >> x;
			s.insert(x);
		}
		else if (command == "remove") {
			cin >> x;
			s.erase(x);
		}
		else if (command == "check") {
			cin >> x;
			if (s.find(x) != s.end()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (command == "toggle") {
			cin >> x;
			if (s.find(x) != s.end()) s.erase(x);
			else s.insert(x);
		}
		else if (command == "all") {
			for (int i = 1; i <= 20; i++) s.insert(i);
		}
		else if (command == "empty") {
			s.clear();
		}
	}

	return 0;
}