#include <bits/stdc++.h>
using namespace std;

int arr[128][128];
int white = 0, blue = 0;
void ColorPaper(int x, int y, int n) {

	int check = arr[y][x];
	bool isNot = false;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] != check) {
				isNot = true;
				break;
			}
		}
		if (isNot) break;
	}


	if (!isNot) {
		if (check == 1) blue++;
		else white++;
	}
	else {
		ColorPaper(x, y, n / 2);
		ColorPaper(x + n / 2, y, n / 2);
		ColorPaper(x, y + n / 2, n / 2);
		ColorPaper(x + n / 2, y + n / 2, n / 2);
	}

}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];

	ColorPaper(0, 0, N);

	cout << white << '\n' << blue;

	return 0;
}