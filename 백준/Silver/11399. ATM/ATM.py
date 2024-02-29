import sys
input = sys.stdin.readline

def main():
    input()
    time = list(map(int, input().split()))
    time.sort()
    total_time = 0
    while time:
        total_time += sum(time)
        time.pop()
    print(total_time)

if __name__ == "__main__":
    main()