DIR = ((1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1))

def bfs(graph, visit, _y, _x, w, h):
    queue = [(_y, _x)]
    visit[_y][_x] = True
    
    while queue:
        y, x = queue.pop()
        for dy, dx in DIR:
            ny, nx = y + dy, x + dx
            if 0 <= nx < w and 0 <= ny < h and graph[ny][nx] and not visit[ny][nx]:
                queue.append((ny, nx))
                visit[ny][nx] = True

def main():
    while 1:
        w, h = map(int, input().split())
        if w == 0 and h == 0:
            break
        
        graph = []
        for _ in range(h):
            li = list(map(int, input().split()))
            graph.append(li)
        
        visit = [[False] * w for _ in range(h)]
        answer = 0
        
        for y in range(h):
            for x in range(w):
                if graph[y][x] and not visit[y][x]:
                    bfs(graph, visit, y, x, w, h)
                    answer += 1
        
        print(answer)
if __name__ == "__main__":
    main()