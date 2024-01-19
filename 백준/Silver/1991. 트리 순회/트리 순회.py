import sys
input = sys.stdin.readline

# 전위 순회 - 루트/왼쪽자식/오른쪽자식
# 중위 순회 - 왼쪽자식/루트/오른쪽자식
# 후위 순회 - 왼쪽자식/오른쪽자식/루트

def preorder(dic: dict, node: str):
    print(node, end='')
    if dic[node][0] != '.':
        preorder(dic, dic[node][0])
    if dic[node][1] != '.':
        preorder(dic, dic[node][1])
        
def inorder(dic: dict, node: str):
    if dic[node][0] != '.':
        inorder(dic, dic[node][0])
    print(node, end='')
    if dic[node][1] != '.':
        inorder(dic, dic[node][1])
               
def postorder(dic: dict, node: str):
    if dic[node][0] != '.':
        postorder(dic, dic[node][0])
    if dic[node][1] != '.':
        postorder(dic, dic[node][1])
    print(node, end='')

def main():
    dic = {}
    for _ in range(int(input())):
        node, left, right = map(str, input().split())
        dic[node] = [left, right]
    preorder(dic, 'A')
    print()
    inorder(dic, 'A')
    print()
    postorder(dic, 'A')

if __name__ == '__main__':
    main()