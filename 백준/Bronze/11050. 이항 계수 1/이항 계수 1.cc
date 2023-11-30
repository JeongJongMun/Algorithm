#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;

	int a = 1;
	int b = 1;
	for (int i = 1; i <= N; i++) a *= i;
	for (int i = 1; i <= N - K; i++) b *= i;
	for (int i = 1; i <= K; i++) b *= i;
	cout << a / b;
	return 0;
}