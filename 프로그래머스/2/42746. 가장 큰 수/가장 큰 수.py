def quick_sort(arr):
    if len(arr) <= 1: return arr

    pivot = arr[len(arr) // 2]
    less, equal, more = [], [], []
    for elem in arr:
        s1 = str(pivot) + str(elem)
        s2 = str(elem) + str(pivot)
        if int(s1) < int(s2):
            less.append(elem)
        elif int(s1) > int(s2):
            more.append(elem)
        else:
            equal.append(elem)
            
    return quick_sort(less) + equal + quick_sort(more)

def solution(numbers):
    sorted_arr = quick_sort(numbers)
    answer = ''.join(str(x) for x in sorted_arr)
    
    return '0' if int(answer) == 0 else answer