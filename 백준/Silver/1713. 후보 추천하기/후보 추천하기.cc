#include <iostream>
#include <map>
#define MAX 200000000

struct info
{
    int nominated = 0;
    int timestamp = 0;
};

std::map<int, info> frames;

void Elapse()
{
    for (auto& [_, info] : frames)
    {
        info.timestamp++;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        Elapse();
        
        int nominated_id;
        std::cin >> nominated_id;
        
        if (frames.count(nominated_id))
        {
            frames[nominated_id].nominated++;
        }
        else
        {
            if (frames.size() >= n)
            {
                int target_id = -1;
                info min_val { MAX, MAX };
                
                for (const auto& [cur_id, cur_info] : frames)
                {
                    if (min_val.nominated > cur_info.nominated || (min_val.nominated == cur_info.nominated && min_val.timestamp < cur_info.timestamp))
                    {
                        min_val = cur_info;
                        target_id = cur_id;
                    }
                }
                
                frames.erase(target_id);
            }
            
            frames[nominated_id] = info{1, 0};
        }
    }
    
    for (const auto& [id, _] : frames)
    {
        std::cout << id << ' ';
    }
    
    return 0;
}