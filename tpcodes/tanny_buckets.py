r=1
b=1
n=1
num=int(input())
while n != num:
    if r%2==1:
        b+=1
        if b==5:
            r+=1
    else:
        b-=1
        if b==1:
            r+=1
    n+=1

#alternate method O(1)
'''
r=num%8
if r==0:
    print('2')
elseif r<5:
    print(r)
else:
    print(10-r)
'''
    
print(b)
