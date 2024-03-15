import sys
input = sys.stdin.readline

def main():
    arr = list(map(int, input().split()))
    arr.sort()
    print(arr[1])    

if __name__ == "__main__":
    main()