import sys
input = sys.stdin.readline
INF = int(1e9)

def main():
    n, c = map(int, input().split())
    houses = []
    for _ in range(n):
        houses.append(int(input().strip()))
    houses.sort()
    # houses.append(houses[-1])
    
    start, end = 0, houses[-1]
    ans = 0
    while start <= end:
        mid = int((start + end) / 2) # 현재 선택한 거리만큼 떨어져 있는 집들 간에 설치할 것임
        
        cnt = c - 1
        point = 0
        for i in range(1, len(houses)):
            if cnt <= 0: break
            if houses[i] - houses[point] >= mid:
                cnt -= 1
                point = i
        # 현재 선택한 거리로 공유기 모두 설치 가능 -> 가장 인접한 두 공유기 사이의 최대 거리 갱신 + 거리 늘리기
        if cnt <= 0:
            ans = mid
            start = mid + 1

        # 현재 선택한 거리로 공유기 모두 설치 불가능 -> 거리 좁히기
        else:
            end = mid - 1
        
    print(ans)
            
            
if __name__ == "__main__":
    main()
