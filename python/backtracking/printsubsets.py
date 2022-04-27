def printsubs(pos,leng,subset):
    if pos == n:
        print(subset[0:leng])
        return
    subset[leng] = a[pos]
    printsubs(pos+1,leng+1,subset)

    printsubs(pos+1,leng,subset)
    
if __name__=="__main__":
    a = [1,2,3,4]
    n = len(a)
    subset = [-1]*n
    pos = 0
    leng = 0
    res = printsubs(pos,leng,subset)
    
