#include <algorithm>
#include <iostream>
#include <vector>

void Print(const std::vector<int>& arr)
{
    for (const int& elem : arr)
    {
        std::cout << elem << ' ';
    }
    
    std::cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    
    int n;
    std::cin >> n;
    
    std::vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
    
    do
    {
        Print(arr);
    } while (std::next_permutation(arr.begin(), arr.end())); 
    
    return 0;
}
