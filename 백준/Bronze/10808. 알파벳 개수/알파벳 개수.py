import sys
input = sys.stdin.readline

def main():
    s = input().strip()
    a = [0] * 26
    for c in s:
        a[ord(c) - 97] += 1
        
    print(*a)
    
if __name__ == "__main__":
    main()