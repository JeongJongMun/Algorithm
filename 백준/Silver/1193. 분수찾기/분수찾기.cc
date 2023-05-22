#include <iostream>
using namespace std;

int main()
{
	int n, line = 0, end = 0, top, bottom;
	cin >> n;

	// 시작점 기준
	// 짝수 라인 분자--, 분모++
	// 홀수 라인 분자++, 분모--
	
	while (n > end) {
		line++;
		end += line;
	}

	// 짝수 라인 일때
	if (line % 2 == 0) {
		top = 1;
		bottom = line;
		for (int i = 0; i < end - n; i++) {
			top++;
			bottom--;
		}
	}
	// 홀수 라인 일때
	else {
		top = line;
		bottom = 1;
		for (int i = 0; i < end - n; i++) {
			top--;
			bottom++;
		}
	}

	cout << bottom << '/' << top;

	return 0;
}