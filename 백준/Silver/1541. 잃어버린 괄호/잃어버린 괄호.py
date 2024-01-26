import sys
input = sys.stdin.readline
    
def main():
    dp = input().strip()
    ans = 0
    
    temp = dp.split('-')
    
    plus = temp[0].split('+')
    for i in plus:
        ans += int(i)
    
    for i in range(1, len(temp)):
        for j in temp[i].split('+'):
            ans -= int(j)
    print(ans)
if __name__ == "__main__":
    main()