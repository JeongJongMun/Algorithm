n = int(input())
tower = list(map(int, input().split()))
ans = [0] * n
stack = []

for i in range(n):
    while stack:
        # 스택의 맨 위 타워의 높이가 현재 타워의 높이보다 크다면 수신 가능 
        if stack[-1][1] > tower[i]:
            ans[i] = stack[-1][0] + 1
            break
        # 아니라면 수신 불가 -> 삭제
        else:
            stack.pop()
    # 각 타워의 인덱스와 높이를 저장
    stack.append([i, tower[i]])
 
print(*ans)