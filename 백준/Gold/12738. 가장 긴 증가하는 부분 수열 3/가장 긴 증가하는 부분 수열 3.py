import sys
from bisect import bisect_left
input = sys.stdin.readline

def main():
    n = int(input().strip())
    arr = list(map(int, input().split()))
    ans = [arr[0]]
    
    for elem in arr[1:]:
        if ans[-1] < elem:
            ans.append(elem)
        else:
            ans[bisect_left(ans, elem)] = elem
    print(len(ans))
    
if __name__ == "__main__":
    main()