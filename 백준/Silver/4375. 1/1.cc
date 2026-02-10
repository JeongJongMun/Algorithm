#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    while (std::cin >> n)
    {
        int tmp = 0;
        
        for (int i = 1; i <= n; i++)
        {
            tmp = tmp * 10 + 1;
            tmp %= n;
            if (tmp == 0)
            {
                std::cout << i << '\n';
                break;
            }
        }
    }
    
    return 0;
}
 