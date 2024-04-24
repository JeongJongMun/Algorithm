import sys
from itertools import accumulate
input = sys.stdin.readline

def main():
    n = int(input().strip())
    honey = list(map(int, input().split()))    
    prefix_sum = list(accumulate(honey))

    ans = 0
    for i in range(1, n - 1):
        # 벌벌꿀
        ans = max(ans, 2 * prefix_sum[-1] - honey[0] - honey[i] - prefix_sum[i])
        # 꿀벌벌
        ans = max(ans, prefix_sum[-1] - honey[-1] - honey[i] + prefix_sum[i - 1])
        # 벌꿀벌
        ans = max(ans, prefix_sum[i] - honey[0] + prefix_sum[-1] - prefix_sum[i - 1] - honey[-1])
    
    print(ans)
        
if __name__ == "__main__":
    main()