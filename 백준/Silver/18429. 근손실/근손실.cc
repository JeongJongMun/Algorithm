#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, answer;
int kit[8];
vector<int> result;
bool isVisited[8];

void DFS() {

	if (result.size() == N) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += result[i];
			if (sum < (i + 1) * K) return;
		}


		if (sum >= N * K) {
			answer++;
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!isVisited[i]) {
			isVisited[i] = true;
			result.push_back(kit[i]);
			DFS();
			result.pop_back();
			isVisited[i] = false;
		}
	}
}

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> kit[i];

	DFS();

	cout << answer;

	return 0;
}