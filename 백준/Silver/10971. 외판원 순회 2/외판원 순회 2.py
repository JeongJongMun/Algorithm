from itertools import permutations

n = int(input())
li = [i for i in range(n)]
arr = [list(map(int, input().split())) for _ in range(n)]
ans = 2e9

for elem in permutations(li):
    temp = 0
    flag = False
    cost = [1000000 if arr[elem[i]][elem[i+1]] == 0 else arr[elem[i]][elem[i+1]] for i in range(len(elem)-1)]
    temp = sum(cost)
    
    temp += 1000000 if arr[elem[-1]][elem[0]] == 0 else arr[elem[-1]][elem[0]]
    ans = min(ans, temp)
    
print(ans)