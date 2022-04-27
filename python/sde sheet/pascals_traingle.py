def printtriangle(r,n):
    for i in range(n):
        print(' '*(n-i-1),end='')
        print(*r[i])
    

def createtriangle(n):
    r = []
    r.append([1])
    if n==1:
        printtriangle(r,n)
    elif n==2:
        r.append([1,1])
        printtriangle(r,n)
    else:
        r.append([1,1])
        for i in range(2,n):
            cur=[]
            cur.append(1)
            for j in range(len(r[i-1])-1):
                cur.append(r[i-1][j]+r[i-1][j+1])
            cur.append(1)
            r.append(cur)
        printtriangle(r,n)

n = 10
createtriangle(n)

    
            
        
    
