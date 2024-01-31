import sys, heapq
input = sys.stdin.readline

def main():
    n = int(input().strip())
    room, lect = [], []
    for _ in range(n):
        s, t = map(int, input().split())
        lect.append((s, t))
    lect.sort()
    
    a, b = lect[0]
    heapq.heappush(room, (b, a))
    for l in lect[1:]:
        if room[0][0] <= l[0]:
            a, b = l
            heapq.heapreplace(room, (b, a))
        else:
            a, b = l
            heapq.heappush(room, (b, a))
    
    print(len(room))
if __name__ == "__main__":
    main()
