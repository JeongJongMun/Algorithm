#include <iostream>
#include <map>
#include <climits>

struct info
{
    int nominated = 0;
    int time = 0;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::map<int, info> frames;
    
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (auto& [id, info] : frames)
        {
            info.time++;
        }
        
        int student_id;
        std::cin >> student_id;
        
        if (frames.find(student_id) != frames.end())
        {
            frames[student_id].nominated++;
        }
        else
        {
            if (cnt >= n)
            {
                info min_info { INT_MAX, 0 };
                int min_id;
                for (const auto& [id, info] : frames)
                {
                    if (min_info.nominated > info.nominated)
                    {
                        min_info.nominated = info.nominated;
                        min_info.time = info.time;
                        min_id = id;
                    }
                    else if (min_info.nominated == info.nominated && min_info.time < info.time)
                    {
                        min_info.time = info.time;
                        min_id = id;
                    }
                }
                
                frames.erase(min_id);
                frames[student_id] = info{1, 0};
            }
            else
            {
                frames[student_id] = info{1, 0};
                cnt++;
            }
        }
    }
    
    for (const auto& [id, _] : frames)
    {
        std::cout << id << ' ';
    }
    
    return 0;
}