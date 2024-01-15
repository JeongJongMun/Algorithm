n = int(input())
pos = [0] * n # 인덱스 = 열 번호, 값 = 행 번호
flag_a = [False] * n # 각 행에 퀸을 배치했는지 체크
flag_b = [False] * (n*2-1) # /
flag_c = [False] * (n*2-1) # \
global cnt 
cnt = 0

def set(n: int, i: int) -> None:
    for j in range(n):
        if not flag_a[j] and not flag_b[i + j] and not flag_c[n - 1 - j + i]:
            pos[i] = j
            if i == n - 1:
                global cnt
                cnt += 1
            else:
                flag_a[j] = flag_b[i + j] = flag_c[n - 1 - j + i] = True
                set(n, i + 1) # 다음 열에 퀸을 배치
                flag_a[j] = flag_b[i + j] = flag_c[n - 1 - j + i] = False
                
set(n, 0)
print(cnt)