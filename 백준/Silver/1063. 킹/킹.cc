#include <iostream>

struct info
{
    int y;
    int x;
    
    bool operator==(const info& other) const
    {
        return y == other.y && x == other.x;
    }
};

info ParseCommand(std::string cmd)
{
    info parsed_command = { 0, 0 };
    
    for (const auto& movement : cmd)
    {
        if (movement == 'R')
        {
            parsed_command.x += 1;
        }
        else if (movement == 'L')
        {
            parsed_command.x -= 1;
        }
        else if (movement == 'B')
        {
            parsed_command.y -= 1;
        }
        else if (movement == 'T')
        {
            parsed_command.y += 1;
        }
    }
    
    return parsed_command;
}

void Move(info& from_k, info& from_r, info amount)
{
    int dx_k = from_k.x + amount.x;
    int dy_k = from_k.y + amount.y;
    
    int dx_r = from_r.x + amount.x;
    int dy_r = from_r.y + amount.y;
    
    if (dx_k > 0 && dx_k <= 8 && dy_k > 0 && dy_k <= 8)
    {
        from_k.x += amount.x;
        from_k.y += amount.y;
        if (dx_k == from_r.x && dy_k == from_r.y)
        {
            if (dx_r > 0 && dx_r <= 8 && dy_r > 0 && dy_r <= 8)
            {
                from_r.x += amount.x;
                from_r.y += amount.y;
            }
            else
            {
                from_k.x -= amount.x;
                from_k.y -= amount.y;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    info king;
    info rock;
    
    std::string king_origin, rock_origin;
    int n;
    std::cin >> king_origin >> rock_origin >> n;
    
    king.x = king_origin[0] - 'A' + 1;
    king.y = king_origin[1] - '1' + 1;
    
    rock.x = rock_origin[0] - 'A' + 1;
    rock.y = rock_origin[1] - '1' + 1;
    
    for (int i = 0; i < n; i++)
    {
        std::string cmd;
        std::cin >> cmd;
        
        info parsed_cmd = ParseCommand(cmd);
        Move(king, rock, parsed_cmd);
    }
    
    std::cout << static_cast<char>(king.x + 'A' - 1) << static_cast<char>(king.y + '1' - 1) << '\n'
              << static_cast<char>(rock.x + 'A' - 1) << static_cast<char>(rock.y + '1' - 1);
    
    return 0;
}