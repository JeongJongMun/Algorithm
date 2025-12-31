#include <iostream>
#include <string>
#include <vector>
#include <climits>

int answer = INT_MIN;
int n;
std::string str;

int Calculate(int n1, int n2, char op)
{
    if (op == '+')
    {
        return n1 + n2;
    }
    if (op == '-')
    {
        return n1 - n2;
    }
    if (op == '*')
    {
        return n1 * n2;
    }
    return 0;
}

void Solve(int idx, int cur)
{
    if (idx > n - 1)
    {
        answer = std::max(answer, cur);
        return;
    }
    
    char prev_op = idx == 0 ? '+' : str[idx - 1];
    
    if (idx + 2 < n)
    {
        int bracket = Calculate(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
        Solve(idx + 4, Calculate(cur, bracket, prev_op));
    }
    
    Solve(idx + 2, Calculate(cur, str[idx] - '0', prev_op));
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin >> n >> str;
    
    Solve(0, 0);
    std::cout << answer;
    
    return 0;
}