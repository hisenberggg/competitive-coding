#maximize the profit (val) by including items in sack as per capacity

def knapsack(wt,val,W,n):
    #if we don't have items or the bag's capacity is 0
    if W == 0 or n == 0:
        return 0

    #check if the value is precalculated
    if t[n][W] != -1:
        return t[n][W]
    
    #check if we got a choice to include an item or not
    if wt[n-1] <= W:
        t[n][W] = max(val[n-1] + knapsack(wt,val,W-wt[n-1],n-1),
                   knapsack(wt,val,W,n-1)) #if not present then store value
        return t[n][W]
    # if we got a choice then include the max profit from either of the choices

    else:
        t[n][W] = knapsack(wt,val,W,n-1) #if not present then store value
        return t[n][W]
    #here didn't got a choice so don't include


if __name__=="__main__":
    wt= [10,20,30]
    val= [60,100,120]
    W=50
    n = len(val)
    
    t = [[-1]*(W+1) for i in range(n+1)]

    print(knapsack(wt,val,W,n))

