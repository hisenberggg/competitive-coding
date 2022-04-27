#video: https://youtu.be/3IETreEybaA

#find the length of longest substring with all unique characters

# complexity 2*N since both pointes might need to traverse entire array in worst case
def longunisubstr(s):

    maxi = 0
    se = set()
    apointer = 0 #initial pointer
    bpointer = 0 #expanding window pointer

    # while bpointer < len(s):
    #     if not s[bpointer] in se: #if the current index char is NOT in set 
    #         se.add(s[bpointer])   # add it to set and
    #         bpointer+=1           #increment pointer
    #         maxi = max(maxi, len(se)) #reocrd the max set size
    #     else:                       #if current is PRESENT in the set then
    #         se.remove(s[apointer])  #remove all elements till first appearance of number from the set 
    #         apointer+=1             #increment the pointer

    while bpointer<len(s):
        if s[bpointer] in se:
            while s[bpointer] in se and apointer<bpointer: #remove all elements till first appearance of number from the set 
                se.remove(s[apointer])
                apointer+=1
        se.add(s[bpointer])
        bpointer+=1
        maxi = max(maxi,len(se))

    return maxi

def longunisubstr2(s):
    map = {}
    maxi = 0
    apointer = 0
    bpointer = 0

    while bpointer<len(s):
        if s[bpointer] in map.keys():
            apointer = max(apointer, map[s[bpointer]]+1)
        maxi = max(maxi,bpointer-apointer+1)
        map[s[bpointer]] = bpointer
        bpointer+=1
    return maxi

if __name__=="__main__":

    s = "abcdabcbb"
 
    res = longunisubstr(s)
    print(res)
