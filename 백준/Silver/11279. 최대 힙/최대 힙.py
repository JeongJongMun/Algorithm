from heapq import *
import sys

hp = []
input()
for x in map(int, sys.stdin):
    heappush(hp, -x) if x else print(-heappop(hp) if hp else 0)