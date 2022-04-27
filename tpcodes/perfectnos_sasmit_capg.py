def divi(n):
    d=[]
    for i in range(1,(n//2)+1):
        if n%i==0:
            d.append(i)
    return d

f,r =map(int,input().split())
l=[]
for i in range(f,r):
    a = divi(i)
    if sum(a)==i:
        l.append(i)
print(l)
