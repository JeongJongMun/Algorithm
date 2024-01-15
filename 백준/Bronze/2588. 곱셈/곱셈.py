from typing import List
def mul(a: int, b: str) -> List:
    return [a*int(b[-1]), a*int(b[-2]), a*int(b[-3]), a*int(b)]

a = int(input())
b = input()

li = mul(a, b)

for elem in li:
    print(elem)