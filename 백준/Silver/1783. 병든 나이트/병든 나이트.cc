#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    if (n <= 1 || m <= 1)
    {
        std::cout << 1;
    }
    else if (n < 3)
    {
        if (m < 3)
        {
            std::cout << 1;
        }
        else if (m < 5)
        {
            std::cout << 2;
        }
        else if (m < 7)
        {
            std::cout << 3;
        }
        else
        {
            std::cout << 4;
        }
    }
    else
    {
        if (m < 5)
        {
            std::cout << m;
        }
        else if (m < 7)
        {
            std::cout << 4;
        }
        else
        {
            std::cout << m - 2; 
        }
    }
    
    return 0;
}
 