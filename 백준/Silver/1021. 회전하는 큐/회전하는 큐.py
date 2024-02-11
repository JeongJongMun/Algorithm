import sys
from collections import deque
input = sys.stdin.readline

def main():
    n, _ = map(int, input().split())
    deq = deque(list(i for i in range(1, n + 1)))
    ans = 0
    for i in list(map(int, input().split())):
        count = min(deq.index(i), len(deq) - deq.index(i))
        ans += count
        # 2번 연산: 왼쪽으로 한 칸 이동
        if count == deq.index(i):
            for _ in range(count):
                deq.append(deq.popleft())
        # 3번 연산: 오른쪽으로 한 칸 이동
        else:
            for _ in range(count):
                deq.appendleft(deq.pop())
        # 1번 연산: 첫 번째 원소 뽑아내기
        deq.popleft()
    print(ans)    

if __name__ == "__main__":
    main()