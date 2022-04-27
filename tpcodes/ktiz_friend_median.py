
import math
c = 0
def median(a):
    a.sort()
    mid = len(a) // 2
    res = (a[mid] + a[~mid]) / 2
    return math.ceil(res)

def getCount(arr,start,end,k):
    if end == len(arr):
        return
    elif start > end:
        return getCount(arr, 0, end + 1,k)
    else:
        if median(arr[start:end + 1]) >= k:
            global c
            c+=1
        return getCount(arr, start + 1, end,k)

def CountPhotos(N,K,A):
    global c
    getCount(A,0,0,K)
    return c
    



n = 3
k = 2
a = [2,2,2]

print(CountPhotos(n,k,a))

N = int(input())
a = input()
Min_Element(N,a)
