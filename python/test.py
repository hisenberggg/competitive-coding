a=[2,5,4,6,9,15,10]
i=1
while i<len(a):
    if a[i]%2 != 0:
        if a[i-1]%2 == 0:
            a[i-1],a[i]=a[i],a[i-1]
            i-=1
            continue
    i+=1
print(a)
