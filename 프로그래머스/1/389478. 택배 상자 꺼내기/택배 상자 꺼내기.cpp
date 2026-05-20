#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) 
{    
    int full_line = n / w; // 택배 박스가 꽉찬 라인의 수
    int spare = n % w;     // 택배 박스가 꽉차지 않은 마지막 라인에 들어갈 박스의 수
    bool is_forward = full_line % 2 == 0; // 마지막 라인에서 정방향인지, 역방향인지
        
    vector<int> boxes(w, full_line);
    
    for (int i = 0; i < spare; i++)
    {
        int index = is_forward ? i : boxes.size() - 1 - i;
        boxes[index]++;
    }

    // 꺼내고자 하는 박스의 행렬 인덱스
    int target_row = (num - 1) / w;
    int target_column = (num - 1) % w;
    
    bool target_is_forward = target_row % 2 == 0;
    
    int target_index = target_is_forward ? target_column : boxes.size() - 1 - target_column;
    
    return boxes[target_index] - target_row;
}