from random import randint
'''
There are many different versions of quickSort that pick pivot
in different ways: 

1. Always pick first element as pivot.
2. Always pick last element as pivot (implemented below)
3. Pick a random element as pivot.
4. Pick median as pivot.
'''

#========= random element as pivote =========
def sort_rand(a):
    if len(a)<2:
        return a
    
    low,same,high = [],[],[]
    p = a[randint(0,len(a)-1)]

    for i in a:
        if i<p:
            low.append(i)
        if i==p:
            same.append(i)
        if i>p:
            high.append(i)

    return sort_rand(low)+same+sort_rand(high)
#=============================================

#========= 1st element as pivote =========
def partition(a,lb,ub):
    no = a[lb]
    l = lb
    u = ub

    while l<u:
        while a[l]<=no and l<u:
            l+=1
        while a[u]>no:
            u-=1

        if l<u:
            a[l],a[u]=a[u],a[l]
    a[lb] = a[u]
    a[u] = no

    return u

def sort_first(a,l,u):
    if l<u:
        p = partition(a,l,u)

        sort_first(a,l,p-1)
        sort_first(a,p+1,u)
    return a
#====================================

if __name__=="__main__":

    n = int(input())
    a = list(map(int,input().split()))
    a = sort_first(a,0,n-1)
    #a = sort_rand(a)

    print(a)


            
        
