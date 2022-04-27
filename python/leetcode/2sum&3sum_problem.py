
def twosum(a,s):
    sums=[]
    se = set()
    for i in range(len(a)): 
        if s-a[i] in se:               #check if the complement exist in set 
            sums.append((a[i],s-a[i])) #if yes then that's the pair
        se.add(a[i])                   #add visited number to set
    return sums


def threesum(a,s):
    sums = []
 
    for i in range(len(a) - 1):#run until len-1 coz next loop starts from i+1
        
        curr_sum = s-a[i]   #find the current sum
        #thats individual 2sum problem
        se = set()
        for j in range(i+1,len(a)):
            if curr_sum-a[j] in se:
                sums.append((a[i], a[j], curr_sum-a[j]))
            se.add(a[j])

    return sums
            
                 

if __name__=="__main__":
    #for 2sum
    #a = [1,15,45,6,10,8] 
    #s = 16 

    #for 3sum
    a = [1, 2, 4, 45, 6, 10, 10, 8]
    s = 22

    a = [1,2,3,4,5,6]
    s = 6
    #print(twosum(a,s))
    print(threesum(a,s))
