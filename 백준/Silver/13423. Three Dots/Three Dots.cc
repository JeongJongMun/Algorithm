#include <iostream>
#include <set>

using namespace std;

int T; // test case
int N; // Number of Dots

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int answer = 0;

		cin >> N;

		set<int> dot;

		int x;
		for (int i = 0; i < N; i++) {
			cin >> x;
			dot.insert(x);
		}

		for (auto iter_i = dot.begin(); iter_i != dot.end(); iter_i++) {
			auto temp_iter_i = iter_i;
			for (auto iter_j = ++temp_iter_i; iter_j != dot.end(); iter_j++)
				if (dot.count(*iter_j + *iter_j - *iter_i)) answer++;
		}

		cout << answer << endl;
	}

	return 0;
}