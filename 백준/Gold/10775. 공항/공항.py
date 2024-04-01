import sys
input = sys.stdin.readline

def main():
    g = int(input().strip())
    p = int(input().strip())
    gate = [0 for _ in range(g + 1)]
    airplains = [int(input().strip()) for _ in range(p)]
    last_gate = [i for i in range(g + 1)]
    
    cnt = 0
    for i in range(p):
        flag = False
        for j in range(last_gate[airplains[i]], 0, -1):
            if not gate[j]:
                gate[j] = 1
                last_gate[airplains[i]] = j
                cnt += 1
                flag = True
                break
        if not flag:
            break
        
    print(cnt)
    
if __name__ == "__main__":
    main()