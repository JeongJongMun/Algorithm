import sys
input = sys.stdin.readline

def check(i, broken):
    for elem in str(i):
        if int(elem) in broken:
            return False
    return True
        
def main():
    n = int(input().strip())
    m = int(input().strip())
    broken = list(map(int, input().split())) if m else []
    ans = abs(100 - n)
    # i = 이동할 곳
    for nums in range(1000001):
        nums = str(nums)
        # 이동할 수 있다면,
        if check(nums, broken):
            ans = min(ans, abs(n - int(nums)) + len(str(nums)))
    
    print(ans)
    
if __name__ == "__main__":
    main()