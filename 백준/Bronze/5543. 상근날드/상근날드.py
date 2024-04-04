import sys
from collections import deque
input = sys.stdin.readline

def main():
    arr = [int(input().strip()) for _ in range(5)]
    print(min(arr[:3]) + min(arr[3:]) - 50)
    
if __name__ == "__main__":
    main()