import sys
input = sys.stdin.readline
    
def main():
    arr = input().strip().split('-')
    
    values = [sum(map(int, s.split('+'))) for s in arr]
    
    print(values[0] - sum(values[1:]))
if __name__ == "__main__":
    main()