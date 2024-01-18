import sys
from itertools import combinations

input = sys.stdin.readline
N, S = map(int, input().strip().split())
arr = list(map(int, input().strip().split()))

cnt = 0
for i in range(1, len(arr) + 1):
    for li in combinations(arr, i):
        if sum(li) == S: 
            cnt += 1
print(cnt)