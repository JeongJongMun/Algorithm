import sys
input = sys.stdin.readline

def main():
    arr = []
    for i in range(5):
        x = int(input().strip())
        if x < 40:
            x = 40
        arr.append(x)
    
    print(int(sum(arr) / 5))
    
    
if __name__ == "__main__":
    main()