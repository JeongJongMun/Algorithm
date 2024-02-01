import sys
from heapq import heappush, heappop
input = sys.stdin.readline

def main():
    n = int(input().strip())
    # lect 배열은 앞으로 넣어야 할 강의들 - 시작 시간 순으로 오름차순 정렬
    lect = []
    for _ in range(n):
        num, s, e = map(int, input().split())
        lect.append((s, e, num))
    lect.sort()
    
    # room 배열은 배정된 강의실들 최소 힙 (종료 시간)
    room = []
    ans = [0] * (n + 1)
    s, e, num = lect[0]
    
    ln = 1
    heappush(room, (e, s, num, ln))
    for l in lect[1:]:
        s, e, num = l
        if s >= room[0][0]:
            done = heappop(room)
            heappush(room, (e, s, num, done[3]))
            ans[done[2]] = done[3]
        else:
            ln += 1
            heappush(room, (e, s, num, ln))
    
    print(len(room))

    while room:
        _, _, num, ln = heappop(room)
        ans[num] = ln
    
    print(*ans[1:], sep='\n')
    
if __name__ == "__main__":
    main()