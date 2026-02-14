#include <iostream>
#include <cmath>

void Divide(double n)
{
    if (n != 1)
    {
        Divide(ceil(n / -2));
    }
    
    if (n == 0)
    {
        std::cout << '1';
    }
    else
    {
        std::cout << abs(static_cast<int>(n) % 2);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    if (n == 0)
    {
        std::cout << 0;
    }
    else
    {
        Divide(n);
    }
    
    return 0;
}