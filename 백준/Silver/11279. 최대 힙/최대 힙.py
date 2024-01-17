import heapq as H,sys;h=[];input()
for x in map(int,sys.stdin):H.heappush(h,-x)if x else print(-H.heappop(h)if h else 0)