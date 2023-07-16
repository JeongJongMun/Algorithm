#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
string str;

int main() {
	
	while (cin >> N >> M) {
		int answer = 0;

		for (int i = N; N <= M; N++) {
			str = to_string(N);
			for (int j = 0; j < 10; j++) {
				if (count(str.begin(), str.end(), j + '0') >= 2) break;
				if (j == 9) answer++;
			}
		}

		cout << answer << "\n";
	}
	return 0;
}