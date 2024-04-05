import sys
input = sys.stdin.readline

def main():
    input()
    s = input().strip()
    ans = 0
    t = ''
    for c in s:
        if ord(c) - 48 < 10:
            t += c
        elif len(t) > 0:
            ans += int(t)
            t = ''
    if len(t) > 0:
        ans += int(t)
    print(ans)
            
if __name__ == "__main__":
    main()