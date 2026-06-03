#include <string>
#include <vector>
#include <algorithm>

struct Node
{
    int x;
    int number;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(const int x, const int number) 
    : x(x), number(number) { }
};

void insert_node(Node* parent, Node* child)
{
    // left child
    if (parent->x > child->x)
    {
        if (parent->left == nullptr)
        {
            parent->left = child;
        }
        else
        {
            insert_node(parent->left, child);
        }
    }
    // right child
    else
    {
        if (parent->right == nullptr)
        {
            parent->right = child;
        }
        else
        {
            insert_node(parent->right, child);
        }
    }
}

void preorder(const Node* node, std::vector<std::vector<int>>& answer)
{
    if (node == nullptr) return;
    answer[0].push_back(node->number);
    preorder(node->left, answer);
    preorder(node->right, answer);
}

void postorder(const Node* node, std::vector<std::vector<int>>& answer)
{
    if (node == nullptr) return;
    postorder(node->left, answer);
    postorder(node->right, answer);
    answer[1].push_back(node->number);
}

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> nodeinfo) 
{
    int n = nodeinfo.size();
    // 노드 번호 기록
    for (int i = 0; i < n; i++)
    {
        nodeinfo[i].push_back(i + 1);
    }
    
    // Y가 큰 순으로 정렬하되, Y가 같다면 X가 작은 순으로 정렬
    std::sort(nodeinfo.begin(), nodeinfo.end(), [](const std::vector<int>& a, const std::vector<int>& b)
    {
        return a[1] != b[1] ? a[1] > b[1] : a[0] < b[0];
    });
    
    // 트리 생성
    Node* root = new Node(nodeinfo[0][0], nodeinfo[0][2]);
    for (int i = 1; i < n; i++)
    {
        Node* child = new Node(nodeinfo[i][0], nodeinfo[i][2]);
        insert_node(root, child);
    }

    std::vector<std::vector<int>> answer(2, std::vector<int>());
    
    preorder(root, answer);
    postorder(root, answer);

    return answer;
}