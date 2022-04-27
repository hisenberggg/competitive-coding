## divide list into sorted and unsorted list and complete the sorted list
##by finding the right place for the 1st element of unsorted list in sorted list
import numpy as np

def insertionsort(a):
    k=0
    for i in range(1,len(a)):
        temp = a[i]
        j=i-1
        while j>= 0 and a[j]>temp:
            a[j+1]=a[j]
            j-=1
        a[j+1]=temp
    print(k,"times")
    return a

n = int(input())
a = np.array([int(i) for i in input().split()])
print(a[12],type(a))

b= insertionsort(a)
print(b)
