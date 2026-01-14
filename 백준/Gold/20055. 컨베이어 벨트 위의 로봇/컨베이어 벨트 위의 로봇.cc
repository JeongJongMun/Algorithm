#include <iostream>
#include <vector>

struct info
{
    int durability = 0;
    bool bIsRobot = false;
};

bool CanProcess(std::vector<info>& convey, const int k)
{
    int cnt = 0;
    for (const auto& [dura, _] : convey)
    {
        if (dura == 0)
        {
            cnt++;
        }
    }
    
    if (cnt >= k)
    {
        return false;
    }
    
    return true;
}

int Process(std::vector<info>& convey, int n, int k)
{
    int step = 0;
    
    while (CanProcess(convey, k))
    {
        // 1. rotate
        info last = convey.back();
        convey.pop_back();
        convey.insert(convey.begin(), last);
        
        if (convey[n - 1].bIsRobot)
        {
            convey[n - 1].bIsRobot = false;
        }
        
        // 2. move robot
        for (int cur = n - 2; cur >= 0; cur--)
        {
            int next = cur + 1;
            if (convey[cur].bIsRobot && convey[next].durability > 0 && !convey[next].bIsRobot)
            {
                convey[next].durability--;
                convey[next].bIsRobot = true;
                convey[cur].bIsRobot = false;
            }
            
            if (convey[n - 1].bIsRobot)
            {
                convey[n - 1].bIsRobot = false;
            }
        }
        
        // 3. put robot
        if (convey[0].durability > 0 && !convey[0].bIsRobot)
        {
            convey[0].durability--;
            convey[0].bIsRobot = true;
        }
        
        step++;
    }
    
    return step;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<info> convey(n * 2);
    for (int i = 0; i < n * 2; i++)
    {
        std::cin >> convey[i].durability; 
    }
    
    std::cout << Process(convey, n, k);
    
    
    return 0;
}