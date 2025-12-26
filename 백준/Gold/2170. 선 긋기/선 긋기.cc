#include <algorithm>
#include <iostream>
#include <vector>

struct Line
{
    int s;
    int e;

    Line(int inX, int inY) : s(inX), e(inY) {}

    bool operator<(const Line& other) const
    {
        if (s != other.s)
        {
            return s < other.s;
        }
        return e < other.e;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<Line> lines;
    int n;
    std::cin >> n;

    int x, y;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x >> y;
        lines.emplace_back(x, y);
    }

    std::sort(lines.begin(), lines.end());

    int answer = 0;
    int start = lines[0].s;
    int end = lines[0].e;
    
    for (int i = 1; i < n; i++)
    {
        if (end >= lines[i].s)
        {
            end = std::max(end, lines[i].e);
        }
        else if (end < lines[i].s)
        {
            answer += end - start;
            start = lines[i].s;
            end = lines[i].e;
        }
    }

    answer += end - start;

    std::cout << answer;
    

    return 0;
}