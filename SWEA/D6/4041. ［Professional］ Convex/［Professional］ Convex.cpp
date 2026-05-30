#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    long long x, y;

    bool operator<(const Point& other) const
    {
        if (x != other.x)
        {
            return x < other.x;
        }
        return y < other.y;
    }
};

long long ccw(const Point& a, const Point& b, const Point& c)
{
    // ab = (b.x - a.x, b.y - a.y)
    // ac = (c.x - a.x, c.y - a.y)
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> monotoneChain(vector<Point>& points)
{
    int n = static_cast<int>(points.size());
    if (n < 3)
    {
        return points;
    }

    sort(points.begin(), points.end());

    vector<Point> lower_hull;
    vector<Point> upper_hull;

    for (int i = 0; i < n; i++)
    {
        while (lower_hull.size() >= 2 && ccw(lower_hull[lower_hull.size() - 2], lower_hull.back(), points[i]) <= 0)
	   {
            lower_hull.pop_back();
        }
        lower_hull.push_back(points[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (upper_hull.size() >= 2 && ccw(upper_hull[upper_hull.size() - 2], upper_hull.back(), points[i]) <= 0)
        {
            upper_hull.pop_back();
        }
        upper_hull.push_back(points[i]);
    }

    lower_hull.insert(lower_hull.end(), upper_hull.begin() + 1, upper_hull.end() - 1);
    return lower_hull;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin >> n;

        vector<Point> points;
        for (int i = 0; i < n; i++)
        {
            long long x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }
		vector<Point> result = monotoneChain(points);
        cout << "#" << test_case << " " << result.size() << '\n';
    }
	return 0;
}