a = int(input())
b = int(input())
c = int(input())

if a == b == c == 60:               # 세 각의 크기가 모두 60인 경우
    print("Equilateral")
elif a + b + c == 180:              # 세 각의 합이 180이고
    if a == b or b == c or c == a:  # 두 각이 같은 경우
        print("Isosceles")
    else:                           # 같은 각이 없는 경우
        print("Scalene")
else:                               # 세 각의 합이 180이 아닌 경우
    print("Error")