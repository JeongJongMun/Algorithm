#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// 26^0 ~ 26^1 = a ~ z
// 26^1 + 1 ~ 26^2 = aa ~ zz
// 27 ~ 676
// 27 ~ 52 = aa ~ az
// 26^2 + 1 ~ 26^3 = aaa ~ zzz
std::string find_n_spell(long long n)
{
    n--;
    
    int length = 1;
    long long count_at_length = 26;

    while (n >= count_at_length)
    {
        n -= count_at_length;
        length++;
        count_at_length *= 26;
    }
    
    std::string spell = "";
    for (int i = length; i > 0; i--)
    {
        long long num = 1;
        for (int j = 0; j < i - 1; j++)
        {
            num *= 26;
        }

        int alphabet = n / num;
        spell += (char)('a' + alphabet);
        n %= num;
    }

    return spell;
}

bool compare(const std::string a, const std::string b)
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
    
    int index = 0;
    while (index != std::upper_bound(bans.begin(), bans.end(), find_n_spell(n + index), compare) - bans.begin())
    {
        std::string spell = find_n_spell(n + index);
        auto iter = std::upper_bound(bans.begin(), bans.end(), spell, compare);
        index = iter - bans.begin();
    }

    return find_n_spell(n + index);
}