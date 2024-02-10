import sys
input = sys.stdin.readline

def main():
    str = input()
    stack = []
    pipe_num, ans, i = 0, 0, 0
    while i < len(str) - 1:
        if str[i] + str[i + 1] == '()':
            ans += pipe_num
            i += 1
        else:
            if str[i] == '(':
                pipe_num += 1
                stack.append(str[i])
            else:
                pipe_num -= 1
                ans += 1
                stack.pop()
        i += 1
    
    print(ans)

if __name__ == "__main__":
    main()