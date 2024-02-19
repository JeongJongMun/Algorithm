import sys
input = sys.stdin.readline

def floyd_warshall(graph, n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                graph[i][j] = graph[i][j] | (graph[i][k] & graph[k][j])
    print('\n'.join(' '.join(map(str, i)) for i in graph))
    
def main():
    n = int(input().strip())
    graph = [list(map(int, input().split())) for _ in range(n)]
    floyd_warshall(graph, n)
        
if __name__ == '__main__':
    main()