import sys

input = sys.stdin.readline
INF = int(1e9)


def main():
    n = int(input().strip())
    s = input().strip()

    chars = {}
    low, high = 0, 0

    max_len = 0
    while high < len(s):
        if s[high] in chars:
            chars[s[high]] += 1
        else:
            chars[s[high]] = 1


        while len(chars) > n:
            chars[s[low]] -= 1
            if chars[s[low]] == 0:
                del chars[s[low]]
            low += 1

        max_len = max(max_len, high - low + 1)
        high += 1

    print(max_len)


if __name__ == "__main__":
    main()