#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 식탁의 길이
int K; // 햄버거를 선택할 수 있는 거리 K
int answer; // 햄버거를 최대로 먹을 수 있는 사람의 수
string pos;

int main() {

	cin >> N >> K;

	cin >> pos;

	for (int i = 0; i < N; i++) {
		if (pos[i] == 'P') {
			for (int j = -K; j < K + 1; j++) {
				if (!(i + j < 0) && !(i + j > N) && j != 0 && pos[i + j] == 'H') {
					answer++;
					pos[i + j] = 'E';
					break;
				}
			}
		}
	}

	cout << answer;

	return 0;
}