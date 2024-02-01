import sys, heapq
from collections import deque
input = sys.stdin.readline

def main():
    n = int(input().strip())
    lect = []
    for _ in range(n):
        num, s, e = map(int, input().split())
        lect.append((s, e, num))
    lect.sort()
    
    # print(*lect, sep='\n')
    room, ans = [], [0] * (n + 1)
    s, e, num = lect[0]
    ln = 1
    
    heapq.heappush(room, (e, s, num, ln))
    for l in lect[1:]:
        s, e, num = l
        # print(*room)
        if s >= room[0][0]:
            a = heapq.heappop(room)
            heapq.heappush(room, (e, s, num, a[3]))
            # print(a, '빼고', (e, s, num, a[3]), '넣음')
            ans[a[2]] = a[3]
        else:
            ln += 1
            heapq.heappush(room, (e, s, num, ln))
            # print(e, s, num, ln, '넣음')
    
    print(len(room))

    while room:
        e, s, num, ln = heapq.heappop(room)
        ans[num] = ln
    
    print(*ans[1:], sep='\n')
    
if __name__ == "__main__":
    main()