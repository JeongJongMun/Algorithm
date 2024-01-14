#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n, x, y, ans = 0;
	bool paper[100][100] = {false,};

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				paper[j + x][k + y] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j] == true) ans++;
		}
	}
	cout << ans;
	return 0;
}