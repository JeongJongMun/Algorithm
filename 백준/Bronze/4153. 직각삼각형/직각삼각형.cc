#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int arr[3];
	while (true) {
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		if (arr[0] == 0 and arr[1] == 0 and arr[2] == 0) break;
		if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2)) cout << "right" << '\n';
		else cout << "wrong" << '\n';
	}

	return 0;
}