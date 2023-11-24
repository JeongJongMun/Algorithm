#include <bits/stdc++.h>
using namespace std;

int arr[10];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int A, B, C; cin >> A >> B >> C;
	string str = to_string(A * B * C);

	for (int i = 0; i < str.length(); i++) {
		arr[int(str[i]) - '0']++;
	}

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}