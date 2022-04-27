def getcombi(a,n):
    if n<0:
        print(''.join(a))
        return
    a[n] = '_'
    getcombi(a,n-2)
    a[n] = ' '
    getcombi(a,n-2)

a= "a b c d"
a = list(a)
getcombi(a,len(a)-2)