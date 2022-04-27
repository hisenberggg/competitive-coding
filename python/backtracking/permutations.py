# https://www.youtube.com/watch?v=f2ic2Rsc9pU&t=32s

def printpermu(op,a,i,n):
    if i==n:
        op.append(a)
        # print(a)
    for j in range(i,n):
        b = a[:]
        b[i],b[j] = b[j],b[i] #swap
        printpermu(op,b,i+1,n)

a = [1,2,3]
n = len(a)
op = []
printpermu(op,a,0,n)
print(op)
