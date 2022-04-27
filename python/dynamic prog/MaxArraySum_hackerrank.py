#find the max sum of subset in arr, elements should not be adjacent  
#https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dynamic-programming


def maxsubsetsum(arr):
    dp[0] = arr[0]
    dp[1] = max(arr[0],arr[1])
    maxi = max(dp[0],dp[1])
    for i in range(2,len(arr)):
        maxi = max(dp.values())
        dp[i] = max(maxi, arr[i], arr[i]+dp[i-2])

    return dp[len(arr)-1]


if __name__ == "__main__" :
    arr = [3,7,4,6,5] #13
    arr1 = [2,1,5,8,4] #11
    dp={}
    op = maxsubsetsum(arr)
    print(op)
