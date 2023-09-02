#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 책의 개수
int answer; // 정답

int main() {

	cin >> N;

	answer = N;

	vector<int> book(N);

	for (int i = 0; i < N; i++) {
		cin >> book[i];
	}

	vector<int> sortedBook(N);
	copy(book.begin(), book.end(), sortedBook.begin());

	sort(sortedBook.begin(), sortedBook.end());

	int current = N - 1;

	for (int i = N - 1; i >= 0; i--) {
		if (book[i] == sortedBook[current]) {
			answer--;
			current--;
		}
	}
		

	cout << answer;

	return 0;
}