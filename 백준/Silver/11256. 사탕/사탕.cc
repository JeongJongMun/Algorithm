#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T; // Test Case
int J, N; // 사탕의 개수, 상자의 개수

int main() {

	cin >> T;

	for (int t = 0; t < T; t++) {

		int answer = 0; // 모든 사탕을 담는데 필요한 상자의 개수
		
		cin >> J >> N;

		vector<int> box(N);

		int x, y;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			box[i] = x * y;
		}

		sort(box.rbegin(), box.rend());

		for (auto i : box) {
			if (J <= 0) break;
			J -= i;
			answer++;
		}

		cout << answer << endl;
	}

	return 0;
}