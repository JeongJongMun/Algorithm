#include <iostream>
#include <algorithm>
using namespace std;

int rgb[1000][3];

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

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
				rgb[i][j] += min(rgb[i - 1][1], rgb[i - 1][2]);
			else if (j == 1)
				rgb[i][j] += min(rgb[i - 1][0], rgb[i - 1][2]);
			else if (j == 2)
				rgb[i][j] += min(rgb[i - 1][0], rgb[i - 1][1]);
		}
	}
	
	cout << *min_element(rgb[N - 1], rgb[N - 1] + 3);
	
	return 0;
}