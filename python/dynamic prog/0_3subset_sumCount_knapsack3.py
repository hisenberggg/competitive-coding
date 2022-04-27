# find the count of subsets that can be formed with the given sum

#same code as subset sum problem
'''
#using recursion-memoization
def subsetcount(arr,n,s):
    if n == 0:
        return 0
    if s == 0:
        return 1

    if t[n][s] != -1:
        return t[n][s]

    if t[n-1][s] <= s:
        t[n][s] = subsetcount(arr,n-1,s-arr[n-1]) + subsetcount(arr,n-1,s)
        return t[n][s]
    else:
        t[n][s] = subsetcount(arr,n-1,s)
        return t[n][s]
'''

#using topdown
def subsetcount(arr,n,s):
    for i in range(n+1):
        for j in range(s+1):
            if i == 0:
                t[i][j] = 0
            if j == 0:
                t[i][j] = 1

    for i in range(1,n+1):
        for j in range(1,s+1):
            if arr[i-1] <= j:
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j]
            else:
                t[i][j] = t[i-1][j]

    return t[i][j],i,j

if __name__=="__main__":
    arr = [2,3,5,6,8,10]
    n = len(arr)
    s = 10
    t=[[-1]*(s+1) for i in range(n+1)]
    
    print(subsetcount(arr,n,s))
    for i in range(n+1):
        print(t[i])

