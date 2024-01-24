import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def postorder(tree, s, e):
    if s > e: return
    root = tree[s]
    right_start = e + 1
    
    for i in range(s + 1, e + 1):
        if root < tree[i]:
            right_start = i
            break
    postorder(tree, s + 1, right_start - 1)
    postorder(tree, right_start, e)
    print(root)    
    
def main():
    preorder = []
    while True:
        try:
            a = int(input())
            preorder.append(a)
        except:
            break    
    postorder(preorder, 0, len(preorder) - 1)
        
if __name__ == '__main__':
    main()