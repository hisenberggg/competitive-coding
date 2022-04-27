#Given a sack with max capacity W you can add items(single item more than once)
# so that the profit is maximum
# wt-> weight of item
# val-> profit of that item
# W-> max capacity of sack

def unbounded(wt,val,W,n):
    if W==0 or n==0:
        return 0

    if wt[n-1]<=W:
        return max(val[n-1] + unbounded(wt,val,W-wt[n-1],n),#the only difference
                                                           #is that dont do n-1
                                                           #here call for n only
                   unbounded(wt,val,W,n-1))
    else:
        return unbounded(wt,val,W,n-1)
    

if __name__=="__main__":

    wt = [2,3,4]
    val = [2,1,12]

    W = 8
    n = len(wt)

    

    res = unbounded(wt,val,W,n)
    print(res)
