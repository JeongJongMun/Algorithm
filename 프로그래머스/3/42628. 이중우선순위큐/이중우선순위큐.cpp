#include <string>
#include <vector>
#include <set>
#include <iterator>

std::vector<int> solution(std::vector<std::string> operations) 
{
    std::multiset<int> ms;
    
    for (const auto& op : operations)
    {
        char command = op[0];
        int num = std::stoi(op.substr(2, op.size()));
        if (command == 'I')
        {
            ms.insert(num);
        }
        else if (num == 1)
        {
            if (!ms.empty())
            {
                ms.erase(std::prev(ms.end()));
            }
        }
        else if (num == -1)
        {
            if (!ms.empty())
            {
                ms.erase(ms.begin());
            }

        }
    }    

    std::vector<int> answer;
    answer.push_back(ms.empty() ? 0 : *ms.rbegin());
    answer.push_back(ms.empty() ? 0 : *ms.begin());
    return answer;
}