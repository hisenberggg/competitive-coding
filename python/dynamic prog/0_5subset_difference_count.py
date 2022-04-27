#find the count of subsets whose difference of the sums(of the subset) is d

#same code as subset sum count
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

    a = [1,1,2,3] #(1,2)(1,3); (1,2)(1,3); (1,1,2)(3)
    n = 4
    d = 1

    '''
Theory:
s1 - s2 = diff
s1 + s2 = sum

therefore, 2*s1 = diff + sum

s1 = (diff + sum)//2
find the number of subsets in array with sum as s1 (subset sum count)
    '''
    s = (d + sum(a))//2
    print('Required sum for diff '+str(d)+':',s)
    
    dp=[[-1]*(s+1) for i in range(n+1)]
    
    res = subscount(a,s,n)
    print(res)
    for i in range(n):
        print(dp[i])
