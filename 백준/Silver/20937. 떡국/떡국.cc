#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 떡국 그릇의 개수
int answer; // 정답

int main() {

	cin >> N;

	vector<int> bowl(500000);

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		bowl[x]++;
		if (answer < bowl[x]) answer = bowl[x];
	}

	cout << answer;

	return 0;
}