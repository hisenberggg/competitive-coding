#using len(a) size array
def merge(a,lb,mid,ub):
    k,i,j=lb,lb,mid+1
    b=[0]*(len(a))

    while i<=mid and j<=ub:
        if a[i]<a[j]:
            b[k]=a[i]
            i+=1
        else:
            b[k]=a[j]
            j+=1
        k+=1

    while i<=mid:
        b[k]=a[i]
        k+=1
        i+=1
    while j<=ub:
        b[k]=a[j]
        k+=1
        j+=1

    for i in range(lb,ub+1):
        a[i]=b[i]
    print(a)

#using ub-lb+1 size array
def merge1(a,lb,mid,ub):
    k,i,j=0,lb,mid+1
    b=[0]*(ub-lb+1)

    while i<=mid and j<=ub:
        if a[i]<a[j]:
            b[k]=a[i]
            i+=1
        else:
            b[k]=a[j]
            j+=1
        k+=1

    while i<=mid:
        b[k]=a[i]
        k+=1
        i+=1
    while j<=ub:
        b[k]=a[j]
        k+=1
        j+=1

    for i in range(len(b)):
        a[lb]=b[i]
        lb+=1
    print(a)

def mergesort(a,l,u):
    mid = (u+l)//2
    if l<u:
        mergesort(a,l,mid)
        mergesort(a,mid+1,u)

        merge1(a,l,mid,u)
            

if __name__=="__main__":
    n=7
    a = [5,4,3,2,1]

    mergesort(a,0,n-1)
    print(*a)
