def rearrangeEvenAndOdd(arr, n) :
    # variables
    j = -1
 
    # quick sort method
    for i in range(0, n) :
         
        # if array of element
        # is odd then swap
        if (arr[i] % 2 == 0) :
            # increment j by one
            j = j + 1
 
            # swap the element
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
         
 
# Driver code       
arr = [ 1,2,3,4,5 ]
n = len(arr)
 
rearrangeEvenAndOdd(arr, n)
 
for i in range(0,n) :
    print( arr[i] ,end= " ")
