t = int(input())
for i in range(t):
    li = list(map(int, input().split()))[1:]
    print('%.3f%%' % (len([x for x in li if x > sum(li)/len(li)])/len(li)*100))