import sys
n=int(input("enter n"))
'''for i in range(1,n+1):
    for j in range(1,i+1):
        print(j,end="")#new syntax
    print()'''
#print number pattern
'''for i in range(1,n+1):
    for j in range(1,i+1):
        sys.stdout.write("%d"%j)#old syntax
    print()    
'''
#print  pattern
'''
*
**
***
****
*****
for i in range(1,n+1):
    for j in range(1,i+1):
        sys.stdout.write("*")
    print() '''   
     
#print * pattern reverse
'''
    *
   **
  ***
 ****

for i in range(1,n+1):
    for j in range(1,n-i+1):
        sys.stdout.write(" ")
    for j in range(1,i+1):
        sys.stdout.write("*")
    print()
    
#another method

for i in range(1,n+1):
    print(" "*(n-i)+"*"*i);
'''









    


