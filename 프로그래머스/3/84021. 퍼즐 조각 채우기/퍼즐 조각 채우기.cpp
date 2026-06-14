#include <vector>
#include <algorithm>
#include <iostream>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

class BlockData
{
public:
    
    BlockData(int n)
    {
        shape.resize(n, std::vector<bool>(n));
    }
    
    
    bool operator==(const BlockData& other)
    {
        if (shape.size() != other.shape.size())
        {
            return false;
        }

        for (int i = 0; i < shape.size(); i++)
        {
            if (shape[i] != other.shape[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    std::vector<std::vector<bool>> shape;

};

void dfs(const std::vector<std::vector<int>>& graph,
         std::vector<std::vector<bool>>& visited,
         std::vector<std::pair<int, int>>& block_pixels,
         int cx, int cy)
{
    int n = graph.size();
    visited[cy][cx] = true;
    block_pixels.push_back({cx, cy});
    
    for (int i = 0; i < 4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && graph[ny][nx] == 1)
        {
            dfs(graph, visited, block_pixels, nx, ny);            
        }
    }
}

std::vector<BlockData> MakeBlockData(std::vector<std::vector<int>>& graph)
{
    int N = graph.size();
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));
    std::vector<BlockData> data;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] != 1 || visited[i][j]) continue;
            
            std::vector<std::pair<int, int>> block_pixels;
            dfs(graph, visited, block_pixels, j, i);            
            
            int min_x, min_y = N;
            int max_x, max_y = -1;
            for (const auto& pixel : block_pixels)
            {
                min_x = std::min(min_x, pixel.first);
                min_y = std::min(min_y, pixel.second);
                max_x = std::max(max_x, pixel.first);
                max_y = std::max(max_y, pixel.second);
            }
            
            int length_x = max_x - min_x + 1;
            int length_y = max_y - min_y + 1;
            int length = std::max(length_x, length_y);
            BlockData block(length);
            
            for (const auto& pixel : block_pixels)
            {
                int rx = pixel.first - min_x;
                int ry = pixel.second - min_y;
                block.shape[ry][rx] = true; 
            }
            data.push_back(block);
        }
    }
    
    return data;
}

int solution(std::vector<std::vector<int>> game_board, std::vector<std::vector<int>> table)
{
    std::vector<BlockData> table_data = MakeBlockData(table);
    std::vector<BlockData> board_data = MakeBlockData(game_board);
    
    int answer = -1;
    return answer;
}