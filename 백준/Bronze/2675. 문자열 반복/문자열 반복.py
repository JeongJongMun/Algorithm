T = int(input())
for t in range(T):
    cnt, S = map(str, input().split())
    for elem in S:
        print(elem * int(cnt), end='')
    print()