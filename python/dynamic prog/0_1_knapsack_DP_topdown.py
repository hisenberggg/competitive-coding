#maximize the profit (val) by including items in sack as per capacity

def knapsack(wt,val,W,n):
    #the base condition converts to initialization
    for i in range(n+1):
        for j in range(W+1):
            if i==0 or j==0:
                t[i][j]=0
                
    for i in range(1,n+1):
        for j in range(1,W+1):
            if wt[i-1]<=j: #check if we got a choice to include an item or not
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j])
            else:
                t[i][j] = t[i-1][j]
                
    return t[i][j]


if __name__=="__main__":
    wt= [10,20,30]
    val= [60,100,120]
    W=50
    n = len(val)
    
    t = [[-1]*(W+1) for i in range(n+1)]

    print(knapsack(wt,val,W,n))

