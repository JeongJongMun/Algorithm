import sys
input = sys.stdin.readline

# 입력
N, M = map(int, input().split())

# 출력
if N*100 >= M:
    print("Yes")
else:
    print("No")