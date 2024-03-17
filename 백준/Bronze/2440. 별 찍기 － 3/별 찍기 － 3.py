import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    for i in range(n, 0, -1):
        for j in range(i):
            print('*', end='')
        print()
    
if __name__ == "__main__":
    main()