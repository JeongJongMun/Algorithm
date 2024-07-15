import sys
sys.setrecursionlimit(10**6)

answer = 0
n = int(input())
column = [True] * n                  # 열
diagonal_up = [True] * (2 * n - 1)   # /
diagonal_down = [True] * (2 * n - 1) # \

def set_queen(i):
    if i == n:
        global answer
        answer += 1
        return
    
    for j in range(n):
        if column[j] and diagonal_up[i + j] and diagonal_down[n - 1 + i - j]:
            column[j] = diagonal_up[i + j] = diagonal_down[n - 1 + i - j] = False
            set_queen(i + 1)
            column[j] = diagonal_up[i + j] = diagonal_down[n - 1 + i - j] = True


set_queen(0)
        
print(answer)