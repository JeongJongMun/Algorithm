import sys
input = sys.stdin.readline
    
def main():
    rock = int(input().strip())
    if (rock - 1) % 4 == 0 or (rock - 3) % 4 == 0:
        print('SK')
    else:
        print('CY')

if __name__ == "__main__":
    main()