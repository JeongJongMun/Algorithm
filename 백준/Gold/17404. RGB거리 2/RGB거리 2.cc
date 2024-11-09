#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int rgb[1000][3];
int dp[1000][3];
int answer = MAX;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, color; cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> color;
			rgb[i][j] = color;
		}
	}

	for (int first = 0; first < 3; first++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i != first)
				dp[0][i] = MAX;
			else
				dp[0][i] = rgb[0][i];
		}
		
		for (int i = 1; i < N; i++)
		{
			dp[i][0] = rgb[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = rgb[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = rgb[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == first) continue;
			answer = min(answer, dp[N - 1][i]);
		}
	}

	cout << answer;
	
	return 0;
}