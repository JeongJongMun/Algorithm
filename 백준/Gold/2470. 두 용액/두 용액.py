import sys
input = sys.stdin.readline


def main():
    n = int(input().strip())
    water = list(map(int, input().split()))
    water.sort()
    
    m = 1e10
    low, high = 0, n - 1
    alow, ahigh = 0, 0
    
    while low < high:
        cur = water[low] + water[high]
        if (abs(cur) < m):
            m = abs(cur)
            alow, ahigh = water[low], water[high]
        
        if cur < 0:
            low += 1
        else:
            high -= 1

    print(alow, ahigh)
    
if __name__ == "__main__":
    main()