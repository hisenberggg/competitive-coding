
#same code as subset sum problem
def equalsubset(arr,n,s):
    if s == 0:
        return True
    if n == 0:
        return False

    if t[n][s] != -1:
        return t[n][s]

    if t[n-1][s] <= s:
        t[n][s] = equalsubset(arr,n-1,s-arr[n-1]) or equalsubset(arr,n-1,s)
        return t[n][s]
    else:
        t[n][s] = equalsubset(arr,n-1,s)
        return t[n][s]

if __name__=="__main__":
    arr = [1,7,7,11]
    n = len(arr)
    s = sum(arr)
    t=[[-1]*(s+1) for i in range(n+1)]

    if s%2 == 0:        #if sum is even then call the subset sum for s/2
        print(equalsubset(arr,n,s//2))
    else:
        print(False)
