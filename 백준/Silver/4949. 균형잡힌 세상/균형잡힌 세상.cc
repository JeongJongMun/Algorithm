#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true) {
		stack<char> s;
		string str;
		getline(cin, str);

		if (str == ".") break;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' or str[i] == '[') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				if (s.empty()) s.push(str[i]);
				else if (s.top() == '(') s.pop();
				else s.push(str[i]);
			}
			else if (str[i] == ']') {
				if (s.empty()) s.push(str[i]);
				else if (s.top() == '[') s.pop();
				else s.push(str[i]);
			}
		}

		if (s.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

	return 0;
}
// ([)]())