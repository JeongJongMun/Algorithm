#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<string> res;

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		for (int j = 1; j < str.length() + 1 - i; j++) {
			res.insert(str.substr(i, j));
		}
	}

	cout << res.size() << endl;
	
	return 0;
}