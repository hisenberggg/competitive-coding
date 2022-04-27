#Find if we can make 2 subsets of equal sum

#same code as subset sum problem
'''
#using recursion-memoization
def equalsubset(arr,n,s):

    if n == 0 and s!=0:
        t[n][s] = False
        return t[n][s]
    if s == 0:
        t[n][s] = True
        return t[n][s]
    
    if t[n][s] != -1:
        return t[n][s]

    if t[n-1][s] <= s:
        t[n][s] = equalsubset(arr,n-1,s-arr[n-1]) or equalsubset(arr,n-1,s)
        return t[n][s]
    else:
        t[n][s] = equalsubset(arr,n-1,s)
        return t[n][s]
'''

#using top down
def equalsubset(arr,n,s):
    for i in range(n+1):
        for j in range(s+1):
            if i == 0:
                t[i][j] = False
            if j == 0:
                t[i][j] = True

    for i in range(1,n+1):#start both loops from 1 cuz 1st row and col is filled
        for j in range(1,s+1):
            if arr[i-1] <= j:
                t[i][j] = t[i-1][j-arr[i-1]] or t[i-1][j]
            else:
                t[i][j] = t[i-1][j]

    return t[i][j]
            

if __name__=="__main__":
    #arr = [1,7,7,11] #false
    arr = [1,7,7,11]  #true
    n = len(arr)
    s = sum(arr)
    t=[[-1]*(s+1) for i in range(n+1)]

    if s%2 == 0:        #if sum is even then call the subset sum for s/2
        print(equalsubset(arr,n,s//2))
    else:
        print(False)
