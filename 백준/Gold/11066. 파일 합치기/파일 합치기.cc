#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int dp[500][500];
int sum[500];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N; cin >> N;
		auto files = vector<int>(N);
		for (int i = 0; i < N; i++)
		{
			cin >> files[i];
			sum[i] = sum[i - 1] + files[i];
		}
		
		for (int start = 1; start < N; start++)
		{
			for (int i = 0, j = start; i < N && j < N; i++, j++)
			{
				dp[i][j] = INT_MAX;
				for (int k = i; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}
		cout << dp[0][N - 1] << '\n';
	}
	
	return 0;
}