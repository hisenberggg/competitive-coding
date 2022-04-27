url = input()
n = int(input())
l = url.split('?')[1]
l = l.split('&')
d={}
for i in l:
    q = i.split('=')
    d[q[0]]=q[1]
for i_n in range(n):
    q = input()
    if q in d.keys():
        print(d[q])
    else:
        print('-1')

    
