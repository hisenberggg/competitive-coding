def ispalind(n):
    n1= str(n)
    rev= n1[::-1]
    if rev==n1:
        return 1
    else:
        return 0

n = int(input())
for i_n in range(n):
    k = int(input())
    while True:
        for i in range(k+1,1000):
            if ispalind(i):
                k1=i
                print("k1",k1)
                break
                
        for i in range(k-1,-1,-1):
            if ispalind(i):
                k2=i
                print("k2",k2)
                break
                
        if ispalind(k1+k2):
            print(k1+k2)
            break
        else:
            k-=1
        
