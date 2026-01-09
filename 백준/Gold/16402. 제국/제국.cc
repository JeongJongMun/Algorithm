#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> parent;

std::string Find(std::string x)
{
    if (x != parent[x])
    {
        parent[x] = Find(parent[x]);
    }
    
    return parent[x];
}

void Union(std::string x, std::string y, bool bRootIsX)
{
    std::string parent_x = Find(x);
    std::string parent_y = Find(y);
    
    if (parent_x != parent_y)
    {
        bRootIsX ? parent[parent_y] = parent_x : parent[parent_x] = parent_y;
    }
    else
    {
        if (bRootIsX)
        {
            parent[parent_y] = x;
            parent[x] = x;
        }
        else
        {
            parent[parent_x] = y;
            parent[y] = y;
        }
    }
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
    
    std::string prefix = "Kingdom of ";
    
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore();
    
    for (int i = 0; i < n; i++)
    {
        
        std::string s;
        getline(std::cin, s);
        
        std::string name = s.substr(prefix.length());
        
        parent[name] = name;
    }
    
    for (int i = 0; i < m; i++)
    {
        std::string s;
        getline(std::cin, s);
        
        std::stringstream ss(s);
        std::string s_name1, s_name2, result;
        
        std::getline(ss, s_name1, ',');
        std::getline(ss, s_name2, ',');
        std::getline(ss, result, ',');
        
        std::string name1 = s_name1.substr(prefix.length());
        std::string name2 = s_name2.substr(prefix.length());
        
        if (result == "1")
        {
            Union(name1, name2, true);
        }
        else if (result == "2")
        {
            Union(name1, name2, false);
        }
    }
    
    for (const auto& [fst, snd] : parent)
    {
        Find(fst);
    }
    
    std::set<std::string> answer;
    for (const auto& [fst, snd] : parent)
    {
        answer.insert(Find(fst));
    }

    std::cout << answer.size() << '\n';
    for (const auto& elem : answer)
    {
        std::cout << prefix << elem << '\n';
    }
    
    return 0;
}