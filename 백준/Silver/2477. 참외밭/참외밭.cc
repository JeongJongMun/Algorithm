#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int melon;
	cin >> melon;

	vector<int> directions;
	vector<int> lengths;
	vector<int>::iterator it;
	int d, l;
	int big_area = 1, small_area = 1;
	int check;
	bool isFirst = false;

	for (int i = 0; i < 6; i++) {
		cin >> d >> l;
		directions.push_back(d);
		lengths.push_back(l);
	}

	vector<pair<int, int>> small_square;
	for (it = directions.begin(); it != directions.end(); it++) {
		if (count(directions.begin(), directions.end(), *it) == 1) {
			big_area *= lengths[it - directions.begin()];
			if (isFirst == false) {
				isFirst = true;
				check = it - directions.begin();
			}
		}
		else {
			small_square.push_back(make_pair(*it, lengths[it - directions.begin()]));
		}
	}

	if (check == 0 || check == 4) {
		small_area = small_square[1].second * small_square[2].second;
	}
	else if (check == 1) {
		small_area = small_square[2].second * small_square[3].second;
	}
	else if (check == 2) {
		small_area = small_square[0].second * small_square[3].second;
	}
	else if (check == 3) {
		small_area = small_square[0].second * small_square[1].second;
	}

	cout << (big_area - small_area) * melon;



	return 0;
}