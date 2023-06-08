#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, sum = 0, mode = 0; // mode = 최빈값
	int flag;
	cin >> n;

	int* input = new int[n];
	int count[8001] = {};

	// 입력받기
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		sum += input[i];
		count[input[i] + 4000]++;
	}

	// 최빈값 체크
	for (int i = 0; i < 8001; i++) {
		if (count[i] > mode) {
			mode = count[i];
			flag = i;
		}
	}

	// 최빈값이 여러개 일 경우 두번째로 작은 값 
	for (int i = flag+1; i < 8001; i++) {
		if (count[i] == mode) {
			flag = i;
			break;
		}
	}

	// 정렬
	sort(input, input + n);

	cout << floor((double)sum / n + 0.5) << endl; // 산술평균
	cout << input[n / 2] << endl; // 중앙값
	cout << flag - 4000 << endl; // 최빈값
	cout << input[n - 1] - input[0] << endl; // 범위

	return 0;
}