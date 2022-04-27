r = int(input())
c = int(input())
if r%2==0:
    t = (r//2)*c
else:
    t1 = (r//2)+1
    t2 = (r//2)
    if c%2==0:
        s1 = (c//2)*t1
        s2 = (c//2)*t2
        t = s1+s2
    else:
        s1 = ((c//2)+1)*t1
        s2 = (c//2)*t2
        t = s1+s2
print(t)
