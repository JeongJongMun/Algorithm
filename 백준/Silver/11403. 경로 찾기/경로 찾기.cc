#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void set_res(vector<vector<int> > &res, vector<vector<int> > v, int i, int j, int N)
{
  stack<int> stack;
  stack.push(j);
  while(!stack.empty())
  {
    j = stack.top();
    stack.pop();
    for(int k = 0; k < N; k++)
    {
      if (v[j][k] == 1 && res[i][k] != 1)
      {
        res[i][k] = 1;
        stack.push(k);
      }
    }
  }
}

int main()
{
  fast;

  int N, num;
  cin >> N;

  vector<vector<int> > v(N, vector<int>(N));
  vector<vector<int> > res(N, vector<int>(N, 0));

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> num;
      v[i][j] = num;
      if (num == 1)
        res[i][j] = 1;
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (v[i][j] == 1)
        set_res(res, v, i, j, N);
    }
  }
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
      cout << res[i][j] << ' ';
    cout << '\n';
  }
}