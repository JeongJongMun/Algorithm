#include <string>
#include <vector>
#include <algorithm>

std::string find_n_spell(long long n)
{
    n--;
    
    int length = 1;
    long long count = 26;

    while (n >= count)
    {
        n -= count;
        length++;
        count *= 26;
    }
    
    std::string spell = "";
    for (int i = length; i > 0; i--)
    {
        count /= 26;
        int alphabet = n / count;
        spell += (char)('a' + alphabet);
        n %= count;
    }

    return spell;
}

bool compare(const std::string& a, const std::string& b)
{
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    return a < b;
}

std::string solution(long long n, std::vector<std::string> bans) 
{
    std::sort(bans.begin(), bans.end(), compare);
    
    int idx = 0;
    while (true)
    {
        std::string spell = find_n_spell(n + idx);
        auto iter = std::upper_bound(bans.begin(), bans.end(), spell, compare);
        int upper_idx = iter - bans.begin();
        
        if (idx == upper_idx) return spell;
        idx = upper_idx;
    }    
}