#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int N;
int arr[31];

int main() {

	// arr[4] = arr[4 - 2] * arr[2] + 2 (+ 2 = arr[0] * 2)
	// arr[i] = arr[i - 2] * arr[2] + arr[i - 4] * 2 + arr[i - 6] * 2
	//			+ ... + arr[0] * 2;

	cin >> N;
	arr[0] = 1; // arr[0] * 2 = 2를 만들기 위함
	arr[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		arr[i] = arr[i - 2] * arr[2];
		for (int j = i - 4; j >= 0; j -= 2) {
			arr[i] += arr[j] * 2;
		}
	}

	cout << arr[N];

	return 0;
}
/*
N : 1 ANS : 0

N : 2 ANS : 3

N : 3 ANS : 0

N : 4 ANS : 11

N : 5 ANS : 0

N : 6 ANS : 41

N : 7 ANS : 0

N : 8 ANS : 153

N : 9 ANS : 0

N : 10 ANS : 571

N : 30 ANS : 299303201

*/