

def fibonacci(n):

    if n == 1 or n == 2:
        return n
    if dp[n] != -1:
        return dp[n]
    dp[n] = fibonacci(n-1) + fibonacci(n-2)
    return dp[n]
    
    #print(dp)

if __name__=="__main__":
    n = int(input())
    dp=[-1]*(n+1)
    no = fibonacci(n)
    print(no)
