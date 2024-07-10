def main():
    n = int(input())
    arr = []
    for _ in range(n):
        x = int(input())
        arr.append(x)
    
    if n <= 2:
        print(sum(arr))
        quit()
    dp = [0] * n
    dp[0] = arr[0]
    dp[1] = arr[0] + arr[1]
    for i in range(2, n):
        dp[i] = max(dp[i - 1], dp[i - 3] + arr[i] + arr[i - 1], dp[i - 2] + arr[i])

    print(max(dp))
if __name__ == "__main__":
    main()