import sys
from heapq import heappop, heappush
input = sys.stdin.readline

def isEmpty(nums):
    for item in nums:
        if item[1] > 0:
            return False
    return True

def main():
    for _ in range(int(input().strip())):
        min_heap = []
        max_heap = []
        nums = {}
        for _ in range(int(input().strip())):
            command, value = map(str, input().split())
            value = int(value)
            if command == 'I':
                if value in nums:
                    nums[value] += 1
                else:
                    nums[value] = 1
                    heappush(min_heap, value)
                    heappush(max_heap, -value)
            elif not isEmpty(nums.items()):
                    if value == 1: # max
                        while -max_heap[0] not in nums or nums[-max_heap[0]] < 1:
                            v = -heappop(max_heap)
                            if v in nums:
                                del(nums[v])
                        nums[-max_heap[0]] -= 1
                    elif value == -1: # min
                        while min_heap[0] not in nums or nums[min_heap[0]] < 1:
                            v = heappop(min_heap)
                            if v in nums:
                                del(nums[v])
                        nums[min_heap[0]] -= 1
        
        if isEmpty(nums.items()):
            print('EMPTY')
        else:
            while min_heap[0] not in nums or nums[min_heap[0]] < 1:
                heappop(min_heap)
            while -max_heap[0] not in nums or nums[-max_heap[0]] < 1:
                heappop(max_heap)
            print(-max_heap[0], min_heap[0])

if __name__ == "__main__":
    main()