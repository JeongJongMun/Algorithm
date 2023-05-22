#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v; // 정렬된 벡터
	vector<int> v2; // 원본 벡터
	vector<int>::iterator it;

	int n, x;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
		v2.push_back(x);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto it : v2) {
		cout << lower_bound(v.begin(), v.end(), it) - v.begin() <<  " ";
	}

	return 0;
}