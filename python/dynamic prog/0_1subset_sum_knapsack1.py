#given an array check if there exist a subset in the array whose sum of items is
#equal to specified sum

#memoiztion approach
def maxsum(arr,s,n):
    #if no items then return false
    if n==0 and s!=0: #s!=0 will only come in recursive coz it wont overwrite that cell
        t[n][s]=False #save every state
        return t[n][s]
    #if we got s as zero then it is our expected sum
    if s==0:
        t[n][s]=True #save every state
        return t[n][s]
    #check for n first so that if s==0(column) also n==0(row) it returns True

    #check is the possibility is calculated already
    if t[n][s] != -1:
        return t[n][s]

    #check if the is choice of adding that number to subset
    if arr[n-1]<=s:
        #if yes then (either add that number add reduce the sum) or (dont add)
        t[n][s] = maxsum(arr,s-arr[n-1],n-1) or maxsum(arr,s,n-1)
        return t[n][s]
    else:
        #dont add in the subset
        t[n][s] = maxsum(arr,s,n-1)
        return t[n][s]
        
'''
#top down approach
def maxsum(arr,s,n):
    #the base condition converts to initialization
    for i in range(n+1):
        for j in range(s+1):
            if i==0:
                t[i][j] = False
            if j==0:
                t[i][j] = True
            


    for i in range(1,n+1):#start both loops from 1 cuz 1st row and col is filled
        for j in range(1,s+1):
            if arr[i-1]<=j: #check if we got a choice to include an item or not
                t[i][j] = t[i-1][j-arr[i-1]] or t[i-1][j]
                #t[i-1][j-arr[i-1]] : included in previous row when sum was j-arr[i-1]
                #t[i-1][j] : included in previous row when sum was j
                #check t[][] table in output for better understanding
            else:
                t[i][j] = t[i-1][j]      
    return t[i][j]
'''

if __name__=="__main__":
    arr = [2,7,3,8,10]
    s = 1
    #arr = [1,14,3,7,13]
    #s = 12

    arr=[1,2,3,4]
    s=1
    
    n = len(arr)
    
    t = [[-1]*(s+1) for i in range(n+1)]

    print(maxsum(arr,s,n))

    for i in range(n+1):
        print(t[i])
