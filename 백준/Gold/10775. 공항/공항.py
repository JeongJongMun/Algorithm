import sys
input = sys.stdin.readline

def main():
    g, p = int(input().strip()), int(input().strip())
    gate = [False for _ in range(g + 1)]
    *last_gate, = range(g + 1)
    airplains = [int(input().strip()) for _ in range(p)]
    
    cnt = 0
    for i in range(p):
        flag = False
        for j in range(last_gate[airplains[i]], 0, -1):
            if not gate[j]:
                gate[j] = True
                flag = True
                last_gate[airplains[i]] = j
                cnt += 1
                break
        if not flag:
            break
        
    print(cnt)
    
if __name__ == "__main__":
    main()