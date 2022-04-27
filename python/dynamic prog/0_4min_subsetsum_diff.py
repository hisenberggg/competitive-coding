# Find the subsets such that the difference of the sum(of the subsets)
# is minumum


#same subset sum problem
def subsetsum(arr,s,n):
    #the base condition converts to initialization
    for i in range(n+1):
        for j in range(s+1):
            if i==0:
                dp[i][j] = False
            if j==0:
                dp[i][j] = True
            
    for i in range(1,n+1):#start both loops from 1 cuz 1st row and col is filled
        for j in range(1,s+1):
            if arr[i-1]<=j: #check if we got a choice to include an item or not
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]      
    return dp[i][j]

def min_diff(dp,n,s):
    a = dp[n][0:s//2+1]
    for i in range(len(a)-1,-1,-1):
        if a[i]==True:
            return i


if __name__=="__main__":

    arr = [4,5,13]
    s = sum(arr)
    n = len(arr)

'''
Theory:
the range of the subset sum is : 0 to sum(arr) (0,s1,s2,....sum(arr))
we need to find minimum diff of the sum

in subsetsum problem the last row of the dp array represents
does subset exist with sum (0,s1,s2..sum(arr)) when s=sum(arr) and n = len(arr)

divide that last row od dp matrix into 2 halfs
for every true in left there exist true  in right

find the 1st true towards the left from the centre
Eg:
0 1 2 3 4 5 6 7 8
T T F T F T F T T
      ^
3 and (8-3)=5 are  the subset sums with minimum difference
      
'''

    dp = [[-1]*(s+1) for i in range(n+1)]

    print(subsetsum(arr,s,n))
 
    print("Minimum difference:",min_diff(dp,n,s))

