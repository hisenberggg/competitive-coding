
def cloclwise(a,n):
    #rotate through diagonal
    for i in range(1,n):
        for j in range(i):
            a[i][j] = a[i][j] + a[j][i]
            a[j][i] = a[i][j] - a[j][i]
            a[i][j] = a[i][j] - a[j][i]
    #rotate vertically through center half
    for i in range(n//2):
        for j in range(n):
            a[j][i] = a[j][i] + a[j][n-i-1]
            a[j][n-i-1] = a[j][i] - a[j][n-i-1]
            a[j][i] = a[j][i] - a[j][n-i-1]


if __name__=='__main__':
    '''
    n = 4
    a = [[1,2,3,4],
         [5,6,7,8],
         [9,10,11,12],
         [13,14,15,16],]
    '''
    n = int(input())
    a = []
    for i in range(n):
        a.append(list(map(int,input().split())))

    print('\nOriginal:')
    for i in range(n):
        print(a[i])
    
    cloclwise(a,n)
    print('\nclockwise:')
    for i in range(n):
        print(a[i]) 
    
    
