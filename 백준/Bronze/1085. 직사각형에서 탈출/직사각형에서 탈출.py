x, y, w, h = map(int, input().split())

print(min(x, w-x, h-y, y))