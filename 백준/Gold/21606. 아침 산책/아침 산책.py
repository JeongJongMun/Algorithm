import sys
from collections import deque
input = sys.stdin.readline
INF = 1e9

# 1) 1 - ... - 1 -> 시작과 끝은 무조건 1
# 2) 1 - 0 - ... - 0 - 1 -> 시작과 끝 사이는 무조건 0
# 3) 두 점 사이의 경로는 유일
# 4) N개의 노드와 N-1개의 에지
# n^2 불가능
# n log n 가능
# n+e log n 가능


# @ a노드에서 시작해서 모든 노드로 가는 산책 경로 구하기
# 1. 0인 경우 방문 처리 하고 큐에 인접 노드 넣기 (지나가기)
# 2. 1인 경우 1인 노드를 방문 처리하고 cnt++ (큐에 집어 넣을 필요도 없음 어짜피 못지나감)
def walk(graph, inout, visited, check, start):
    _visited = visited.copy()
    que = deque([start])
    cnt = 0
    while que:
        node = que.popleft()
        for next_node in graph[node]:
            if not _visited[next_node] and inout[next_node] == 0:
                que.append(next_node)
                _visited[next_node] = True
            elif inout[next_node] == 1 and next_node != start:
                cnt += 1
    return cnt
                  
def main():
    v = int(input().strip())
    inout = list(map(int, input().strip()))
    inout = [0] + inout
    graph = [[] for _ in range(v + 1)]
    visited = [True if inout[i] else False for i in range(v+1) ]
    # check = [[0] * (v + 1)] * (v + 1)
    for _ in range(v - 1):
        a, b = map(int, input().strip().split())
        graph[a].append(b)
        graph[b].append(a)
    
    ans = 0
    for start in range(1, v + 1):
        if visited[start]:
            ans += walk(graph, inout, visited, _, start)
    
    print(ans)
    
if __name__ == '__main__':
    main()