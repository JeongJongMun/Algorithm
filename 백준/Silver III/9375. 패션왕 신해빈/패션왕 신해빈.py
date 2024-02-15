import sys
input = sys.stdin.readline

def main():
    for _ in range(int(input().strip())):
        dic = {}
        ans = 1
        for _ in range(int(input().strip())):
            _, t = map(str, input().split())
            dic[t] = dic[t] + 1 if t in dic else 2
        for i in dic:
            ans *= dic[i]
        print(ans - 1)

if __name__ == "__main__":
    main()