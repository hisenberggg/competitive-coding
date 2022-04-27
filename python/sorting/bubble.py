## take the greatest number to the last by multiple swaps
import numpy as np

def bubblesort(a):
    k=0
    for i in range(len(a)):
        flag=False
        for j in range(len(a)-i-1):
            k+=1
            if a[j]>a[j+1]:
                a[j],a[j+1]=a[j+1],a[j]
                flag=True
            print(a)
        if not flag:
            break
    print(k,"times")
    return a

n = int(input())
a = np.array([int(i) for i in input().split()])


b= bubblesort(a)
print(b)
