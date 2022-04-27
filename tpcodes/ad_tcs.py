n = int(input())
a = []
f=0
for i in range(n):
    a.append(int(input()))

k = int(input())
for i in range(0,n,3):
    if not k in a[i:i+3]:
        f=1
        break
if f==0:
    print('1')
else:
    print('0')
