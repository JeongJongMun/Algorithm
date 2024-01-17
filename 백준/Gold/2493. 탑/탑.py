n = int(input())
tower = list(map(int, input().split()))
ans = [0] * n
stack = []

for i in range(n):
    while stack:
        if tower[stack[-1]] > tower[i]:
            ans[i] = stack[-1] + 1
            break
        else:
            stack.pop()
    stack.append(i)
 
print(*ans)