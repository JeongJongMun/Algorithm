n = int(input())
arr = []
for _ in range(n):
    arr.append(list(input()))
    
# 시작 x, 시작 y, n만큼 검사
def quad_tree(x, y, n):
    check = arr[x][y]
    flag = False
    for i in range(n):
        for j in range(n):
            if arr[x+j][y+i] != check: flag = True
    
    if flag:
        nn = n//2
        print('(', end='')
        quad_tree(x, y, nn)
        quad_tree(x, y + nn, nn)
        quad_tree(x + nn, y, nn)
        quad_tree(x + nn, y + nn, nn)
        print(')', end='')
    else:
        print(check, end='')
        
quad_tree(0, 0, n)