import sys

input = sys.stdin.readline


def main():
    n = int(input().strip())
    s = set()
    for _ in range(n):
        name, commute = map(str, input().split())
        if commute == "enter":
            s.add(name)
        else:
            s.remove(name)
    s = sorted(s, reverse=True)

    print(*s, sep="\n")


if __name__ == "__main__":
    main()
