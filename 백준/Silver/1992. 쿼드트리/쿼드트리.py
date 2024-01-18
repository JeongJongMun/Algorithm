import sys
input = sys.stdin.readline
n = int(input().strip())
arr = []
for _ in range(n):
    arr.append(list(input().strip()))
    
def quad_tree(x, y, n):
    check = arr[x][y]
    for i in range(n):
        for j in range(n):
            if arr[x+j][y+i] != check:
                nn = n//2
                print('(', end='')
                quad_tree(x, y, nn)
                quad_tree(x, y + nn, nn)
                quad_tree(x + nn, y, nn)
                quad_tree(x + nn, y + nn, nn)
                print(')', end='')
                return
    print(check, end='')

quad_tree(0, 0, n)