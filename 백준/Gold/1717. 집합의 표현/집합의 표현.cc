#include <iostream>
#include <vector>

std::vector<int> parent;

int find_root(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    
    parent[x] = find_root(parent[x]);
    return parent[x];
}

void union_root(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    
    if (x != y)
    {
        parent[x] = y;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    for (int i = 0; i <= n; i++)
    {
        parent.push_back(i);
    }
    
    for (int i = 0; i < m; i++)
    {
        int operation, x, y;
        std::cin >> operation >> x >> y;
        
        if (operation == 0)
        {
            union_root(x, y);
        }
        else if (operation == 1)
        {
            int parent_x = find_root(x);
            int parent_y = find_root(y);
            
            if (parent_x == parent_y)
            {
                std::cout << "YES" << "\n";
            }
            else
            {
                std::cout << "NO" << "\n";
            }
        }
    }
    
    return 0;
}