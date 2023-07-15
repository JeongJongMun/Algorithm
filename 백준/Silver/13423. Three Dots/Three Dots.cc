#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int T; // test case
int N; // Number of Dots
int answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		
		cin >> N;

		set<int> dot;

		int x;
		for (int i = 0; i < N; i++) {
			cin >> x;
			dot.insert(x);
		}

		for (auto iter_i = dot.begin(); iter_i != dot.end(); iter_i++) {
			auto temp_iter_i = iter_i;
			for (auto iter_j = ++temp_iter_i; iter_j != dot.end(); iter_j++) {
				if (dot.find(*iter_j + *iter_j - *iter_i) != dot.end()) answer++;
				//cout << *iter_i << " " << *iter_j << endl;
			}
		}

		cout << answer << endl;
		answer = 0;
		//cout << endl;
	}

	return 0;
}