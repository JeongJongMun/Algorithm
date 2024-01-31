import sys
input = sys.stdin.readline

def main():
    s = int(input())
    n = 0
    while n * (n + 1) / 2  + n < s:
        n += 1
    print(n)
    
if __name__ == "__main__":
    main()