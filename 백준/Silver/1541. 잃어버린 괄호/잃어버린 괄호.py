import sys
input = sys.stdin.readline
    
def main():
    arr = input().strip().split('-')
    ans = 0
    
    plus = arr[0].split('+')
    for i in plus:
        ans += int(i)
    
    for i in range(1, len(arr)):
        for j in arr[i].split('+'):
            ans -= int(j)
    print(ans)
if __name__ == "__main__":
    main()