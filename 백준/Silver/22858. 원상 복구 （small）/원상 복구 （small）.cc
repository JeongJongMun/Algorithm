#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

int N, K;

int main() 
{

	cin >> N >> K;
	vector<int> S(N + 1);
	vector<int> D(N + 1);
	vector<int> P(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> S[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
	}


	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= N; j++) {
			P[D[j]] = S[j];
		}
		copy(P.begin(), P.end(), S.begin());
	}

	for (int i = 1; i <= N; i++) {
		cout << P[i] << " ";
	}

	return 0;
}