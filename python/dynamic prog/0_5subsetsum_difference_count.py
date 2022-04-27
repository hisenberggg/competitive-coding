

def subscount(a,s,n):
    for i in range(n+1):
        for j in range(s+1):
            if i==0:
                dp[i][j]=0
            if j==0:
                dp[i][j]=1
    for i in range(1,n+1):
        for j in range(1,s+1):
            if a[i-1]<=j:
                dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j] 
            else:
                dp[i][j] = dp[i-1][j]

    return dp[n][s]

if __name__=="__main__":

    a = [1,1,2,3]
    n = 4
    d = 1

    s = (d + sum(a))//2
    print('Required sun for diff '+str(d)+':',s)
    dp=[[-1]*(s+1) for i in range(n+1)]
    
    res = subscount(a,s,n)
    print(res)
    for i in range(n):
        print(dp[i])
