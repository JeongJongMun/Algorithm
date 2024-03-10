import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    li = []
    for _ in range(n):
        name, korean, english, math = map(str, input().split())
        korean, english, math = int(korean), int(english), int(math)
        li.append((name, korean, english, math))
        
    li.sort(key=lambda x: (-x[1], x[2], -x[3], x[0]))
    for i in li:
        print(i[0])

if __name__ == "__main__":
    main()