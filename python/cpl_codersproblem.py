'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
t=int(input())
for tc in range(t):
    n=int(input())
    for t1 in range(n):
        a= input().split()
        if a[1]=="Green":
            if a[2]=="red":
                for i in range(len(a[0])-1):
                    if a[0][i]==a[1]:
                        res="Yes"
                        break
            elif a[3]=="yes":
                vowels=0
                for i in a[0]:
                    if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u' or i=='A' or i=='E' or i=='I' or i=='O' or i=='U'):
                        vowels=vowels+1
                        
                if vowels==2:
                    res="Yes"
                else:
                    res="NO"
            elif a[3]=="no":
                vowels=0
                for i in a[0]:
                    if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u' or i=='A' or i=='E' or i=='I' or i=='O' or i=='U'):
                        vowels=vowels+1
                        
                if vowels==3:
                    res="Yes"
                else:
                    res="No"

        else:
            res="No"
        
        print(res)   
            
    
