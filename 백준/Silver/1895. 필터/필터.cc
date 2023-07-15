#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int image[40][40];
int N, M, T;
vector<int> v;
int answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> image[i][j];
		}
	}
	cin >> T;

	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M-2; j++) {
			for (int k = i; k < i+3; k++) {
				for (int q = j; q < j+3; q++) {
					v.push_back(image[k][q]);
				}
			}
			sort(v.begin(), v.end());
			if (v[4] >= T) answer++;
			v.clear();
		}
	}

	cout << answer;

	return 0;
}