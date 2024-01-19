import sys
input = sys.stdin.readline

# 전위 순회 - 루트/왼쪽자식/오른쪽자식
# 중위 순회 - 왼쪽자식/루트/오른쪽자식
# 후위 순회 - 왼쪽자식/오른쪽자식/루트
tree = {}

def preorder(root: str):
    if root != '.':
        print(root, end='')
        preorder(tree[root][0])
        preorder(tree[root][1])
        
def inorder(root: str):
    if root != '.':
        inorder(tree[root][0])
        print(root, end='')
        inorder(tree[root][1])
               
def postorder(root: str):
    if root != '.':
        postorder(tree[root][0])
        postorder(tree[root][1])
        print(root, end='')

def main():
    for _ in range(int(input())):
        node, left, right = map(str, input().split())
        tree[node] = [left, right]
    preorder('A')
    print()
    inorder('A')
    print()
    postorder('A')

if __name__ == '__main__':
    main()