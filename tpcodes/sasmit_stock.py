n = int(input())
a = list(map(int,input().split()))
s=0
s1=0
for i in sorted(a):
    k=a.index(i)+1
    if s==n:
        break
    if s1+k*a[k-1]<=n:
        s+=k
        s1 += k*a[k-1]
    else:
        #code to avoid the loop for choosing previous factor
        diff=s1+k*a[k-1]-n #difference after adding all possible number of times
        t1 = diff%a[k-1] #how much mod above n
        t2 = n-s1-(a[k-1]-t1) #subtract rest of that number from n to get the previous factor
        if t2>0:
            t3=t2//a[k-1] #number to add
            s+=t3
            s1+=t3*a[k-1] 
    
print(s)
