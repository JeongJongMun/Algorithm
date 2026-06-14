#include <vector>
#include <algorithm>
#include <iostream>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

class BlockData
{
public:
    
    bool operator==(const BlockData& other)
    {
        if (points.size() != other.points.size())
        {
            return false;
        }
        
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i].first != other.points[i].first ||
                points[i].second != other.points[i].second)
            {
                return false;
            }
        }
        return true;
    }
    
    void rotate()
    {
        for (auto& point : points)
        {
            // (y, x) -> (x, -y)
            int y = point.first;
            int x = point.second;
            point.first = x;
            point.second = -y;
        }
        
        normalize();
    }
    
    void normalize()
    {
        int min_x = 10, min_y = 10;
        for (const auto& point : points)
        {
            min_x = std::min(min_x, point.second);
            min_y = std::min(min_y, point.first);
        }
        
        for (auto& point : points)
        {
            point.first -= min_y;
            point.second -= min_x;
        }
        
        std::sort(points.begin(), points.end());
    }
    
    std::vector<std::pair<int, int>> points;
};

void dfs(const std::vector<std::vector<int>>& graph,
         std::vector<std::vector<bool>>& visited,
         std::vector<std::pair<int, int>>& block_pixels,
         int cy, int cx, bool is_table)
{
    int n = graph.size();
    visited[cy][cx] = true;
    block_pixels.push_back({cy, cx});
    
    for (int i = 0; i < 4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && graph[ny][nx] == (is_table ? 1 : 0))
        {
            dfs(graph, visited, block_pixels, ny, nx, is_table);        
        }
    }
}

void MakeBlockData(std::vector<std::vector<int>>& graph, std::vector<BlockData>& data, bool is_table)
{
    int N = graph.size();
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] != (is_table ? 1 : 0) || visited[i][j]) continue;
            
            std::vector<std::pair<int, int>> block_pixels;
            dfs(graph, visited, block_pixels, i, j, is_table);            
            
            int min_x = N, min_y = N;
            for (const auto& pixel : block_pixels)
            {
                min_y = std::min(min_y, pixel.first);
                min_x = std::min(min_x, pixel.second);
            }
            
            BlockData block;
            
            for (const auto& pixel : block_pixels)
            {
                int ry = pixel.first - min_y;
                int rx = pixel.second - min_x;
                block.points.push_back({ry, rx}); 
            }
            std::sort(block.points.begin(), block.points.end());
            data.push_back(block);
        }
    }    
}

int solution(std::vector<std::vector<int>> game_board, std::vector<std::vector<int>> table)
{
    std::vector<BlockData> table_data;
    std::vector<BlockData> board_data;
    MakeBlockData(table, table_data, true);
    MakeBlockData(game_board, board_data, false);
    
    std::vector<bool> used(table_data.size(), false);
    
    int answer = 0;

    for (int i = 0; i < board_data.size(); i++)
    {
        bool is_match = false;
        for (int j = 0; j < table_data.size(); j++)
        { 
            if (used[j]) continue;
            
            BlockData original_block = table_data[j];
            
            for (int k = 0; k < 4; k++)
            {
                if (original_block == board_data[i])
                {
                    answer += original_block.points.size();
                    used[j] = true;
                    is_match = true;
                    break;
                }
                original_block.rotate();
            }
            if (is_match) break;
        }
    }
    
    return answer;
}