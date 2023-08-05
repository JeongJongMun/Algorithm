#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vector<int> prefix_sum(N+1);

	int x;
	int sum = 0;
	for (int i = 1; i < N+1; i++) {
		cin >> x;
		sum += x;
		prefix_sum[i] = sum;
	}

	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		cout << prefix_sum[end] - prefix_sum[start - 1] << "\n";
	}

	return 0;
}