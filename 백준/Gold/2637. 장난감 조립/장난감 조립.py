import sys
from collections import deque
input = sys.stdin.readline

def main():
    v = int(input().strip())
    graph = [[] for _ in range(v + 1)]
    indegree = [0] * (v + 1)
    needs = [[0] * (v + 1) for _ in range(v + 1)]
    
    for _ in range(int(input().strip())):
        a, b, c = map(int, input().split())
        # after를 만드는데 before가 cost개 필요하다.
        # b가 c개 있어야 a로 간다.
        graph[b].append((a, c))
        indegree[a] += 1
        
    que = deque([i for i in range(1, v + 1) if indegree[i] == 0])
    
    while que:
        before = que.popleft()
        for after, cost in graph[before]:
            # 기본 부품이라면
            if needs[before].count(0) == v + 1:
                needs[after][before] += cost
            # 중간 부품 or 완제품이라면
            else:
                for i in range(1, v + 1):
                    needs[after][i] += needs[before][i] * cost
            
            indegree[after] -= 1
            if indegree[after] == 0: que.append(after)
    
    for x in enumerate(needs[v]):
        if x[1] > 0: print(*x)
    
if __name__ == "__main__":
    main()