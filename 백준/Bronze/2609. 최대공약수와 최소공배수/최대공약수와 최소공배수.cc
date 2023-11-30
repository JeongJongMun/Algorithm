#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int GCD(int a, int b)
{
	// 둘 다 0이 아닌 경우 GCD(b, a % b)
	return a == 0 ? b : b == 0 ? a : GCD(b, a % b); 
}

int LCM(int a, int b)
{
	// 어느 하나라도 0이면 LCM은 0
	return (a != 0 && b != 0) ? a / GCD(a, b) * b : 0;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int A, B; cin >> A >> B;

	cout << GCD(A, B) << '\n' << LCM(A, B);

	return 0;
}