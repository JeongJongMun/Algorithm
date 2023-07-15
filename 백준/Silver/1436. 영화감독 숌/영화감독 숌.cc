#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	string tempStr;
	int i;
	int count = 0;
	for (i = 666; i < INT_MAX; i++) {
		tempStr = to_string(i);
		if (tempStr.find("666") != string::npos)count++;
		if (count == N) break;
	}

	cout << i;

	return 0;
}