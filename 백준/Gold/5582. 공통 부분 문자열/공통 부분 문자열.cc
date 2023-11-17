#include <bits/stdc++.h>
using namespace std;

int length[4001][4001];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int answer = 0;
	string a = " ";
	string b = " ";

	string temp;
	cin >> temp;
	a += temp;
	cin >> temp;
	b += temp;


	for (int i = 1; i < a.length(); i++) {
		int ip = i;
		int jp = INT_MAX;
		for (int j = 1; j < b.length(); j++) {
			jp = j;
			if (a[i] == b[j]) {
				length[i][j] = length[i - 1][j - 1] + 1;
				answer = max(answer, length[i][j]);
				jp = min(j, jp);
			}
			else {
				i = ip;
				j = jp;
				jp = INT_MAX;
			}
		}
	}

	cout << answer;

	return 0;
}