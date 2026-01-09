#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, std::string> parent;
std::unordered_map<std::string, int> rank;

std::string Find(std::string x)
{
    if (x != parent[x])
    {
        parent[x] = Find(parent[x]);
    }
    
    return parent[x];
}

void Union(std::string x, std::string y)
{
    x = Find(x);
    y = Find(y);
    
    if (x != y)
    {
        if (rank[x] < rank[y])
        {
            parent[x] = y;
            rank[y] += rank[x];
        }
        else
        {
            parent[y] = x;
            rank[x] += rank[y];
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int test_case;
    std::cin >> test_case;
    
    for (int i = 0; i < test_case; i++)
    {
        parent.clear();
        rank.clear();
        
        int friends;
        std::cin >> friends;
        
        for (int j = 0; j < friends; j++)
        {
            std::string x, y;
            std::cin >> x >> y;

            if (parent.find(x) == parent.end())
            {
                parent[x] = x;
                rank[x] = 1;
            }
            if (parent.find(y) == parent.end())
            {
                parent[y] = y;
                rank[y] = 1;
            }
            Union(x, y);
            
            std::string parent_x = Find(x);

            std::cout << rank[parent_x]<< "\n";
        }
    }
    
    return 0;
}