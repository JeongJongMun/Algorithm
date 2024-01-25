import sys
input = sys.stdin.readline
    
def main():
    n = int(input().strip())
    n += 1
    li = [0] * n
    li[1] = 1
    for i in range(2, len(li)):
        li[i] = li[i - 1] + li[i - 2]
    
    print(li[n - 1])
    
if __name__ == "__main__":
    main()