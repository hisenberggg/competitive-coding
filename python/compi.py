'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here

t=int(input())
for tc in range(t):
    res=""
    n=int(input())
    for t1 in range(n):
        a= input().split()
        if a[1]=="Green":
            if a[2]=="Red":
                for i in range(len(a[0])-1):
                    if a[0][i]==a[0][i+1]:
                        res="Yes"
                        break
                    
            if a[3]=="yes" and res!="Yes":
                vowels=0
                for i in a[0]:
                    if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u' ):
                        vowels=vowels+1
                        
                if vowels==2:
                    res="Yes"
                
            if a[3]=="no" and res!="Yes":
                vowels=0
                for i in a[0]:
                    if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u' ):
                        vowels=vowels+1
                        
                if vowels==3:
                    res="Yes"
                

        else:
            res="No"
        if res=="":
            res="No"
        print(res)

        '''2
2
prabodh Green White yes
sanket Brown Black yes
2
sankett Green Red yes
pprabodh Blue Red no'''
