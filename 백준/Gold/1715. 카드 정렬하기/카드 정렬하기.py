import sys, heapq
input = sys.stdin.readline

def main():
    n = int(input().strip())
    cards = [int(input().strip()) for _ in range(n)]
    heapq.heapify(cards)
    
    cnt = 0
    while 1:
        a = heapq.heappop(cards)
        if len(cards) <= 0: break
        b = heapq.heappop(cards)
        heapq.heappush(cards, a + b)
        cnt += a + b
    print(cnt)
    
if __name__ == "__main__":
    main()