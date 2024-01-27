import sys
input = sys.stdin.readline
    
def main():
    arr = [int(input().strip()) for _ in range(int(input().strip()))]
    arr.sort()
    cnt = 0
    for idx, low in enumerate(arr):
        temp = 1
        for high in arr[idx + 1:]:
            if low < high < low + 5:
                temp += 1
            else: break
        cnt = max(cnt, temp)
    
    print(max(0, (5 - cnt)))
    
if __name__ == "__main__":
    main()