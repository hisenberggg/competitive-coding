
def beautifulno(N):
    n=N+1
    while True:
        n_s = str(n)
        f=0
        s=set(n_s)
        print(s)
        for i in s:
            if n_s.count(i) != int(i):
                print(n_s.count(i),i,n_s)
                f=1
                break
        if f==0:
            print(n)
            break
        n+=1
            
n=119
beautifulno(n)
