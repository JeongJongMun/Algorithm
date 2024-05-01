ax, ay, az = map(int, input().split())
cx, cy, cz = map(int, input().split())

print(cx - az, int(cy / ay), cz - ax)