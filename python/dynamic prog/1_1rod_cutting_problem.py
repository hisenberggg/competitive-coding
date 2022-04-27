#same code as unbounded knapsack

#recursion
def rod_cutting_R(length,price,L,n):
    if L==0 or n==0:
        dp[n][L] = 0
        return dp[n][L]
    
    if dp[n][L] != -1:
        return dp[n][L]

    if length[n-1]<=L:
        dp[n][L] = max(price[n-1]+rod_cutting_R(length,price,L-length[n-1],n),
                       rod_cutting_R(length,price,L,n-1))
        return dp[n][L]
    else:
        dp[n][L] = rod_cutting_R(length,price,L,n-1)
        return dp[n][L]

#memoization 
def rod_cutting_M(length,price,L,n):
    for i in range(n+1):
        for j in range(L+1):
            if i==0 or j==0:
                dp[i][j]=0

    for i in range(1,n+1):
        for j in range(1,L+1):
            if length[i-1]<=j:
                dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]]
                               , dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][L]

if __name__=="__main__":

    L = 8
    price = [2,4,5,6,8]
    #lenght = [i for i in range(1,n+1)]  #if length array not given
    length = [2,3,5,1,4]

    n = len(length)

    dp = [[-1]*(L+1) for i in range(len(length)+1)]

    res = rod_cutting_R(length,price,L,n)
    print(res)

    for i in range(len(length)):
        print(dp[i])
