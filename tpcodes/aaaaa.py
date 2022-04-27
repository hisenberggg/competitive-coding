s,n=input().split()
n=int(n)
s1=""
i=0
while i<len(s):
    c=s.count(s[i])
    if s[i:c] == s[i]*c:
        print(s[i:c+1])
        if c != n:
            s1+=(s[i]*c)
        i+=c
    else:
        s1+=(s[i])
        i+=1
print(s1)
