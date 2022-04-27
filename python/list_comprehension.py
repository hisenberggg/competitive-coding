'''
syntax

expression for var in collection
---returns list


n=int(input('enter n :'))
a= [i*i for i in range(0,n+1)]
print(a)
#--generate all i^2 where i in range 1 to n

print([i*i for i in range(0,int(input('enter n :'))+1)]) #one line program

#Prog-generate i^2 where i is multiple of 3
#syntax --- expression for var in collection condition

a = [i*i for i in range(0,n+1) if(i%3==0)]
    [ ^ ][  ^                 ][      ^ ] 
      |     |                         |
      3     1                         2

print(a)
'''
'''
#Prog-print vowel in as string
s=input('Enter a string:')
a=[ch for ch in s if ch in 'aeiouAEIOU']
print(a)
'''
'''
#Prog- print all perfect square in range
n=int(input('Enter n :'))
a=[ i**2 for i in range(n) if i**2<n ]
print(a)
'''
'''
x= [[a,b] for a in range(1,3) for b in range(a,4)]
print(x)
'''
n = int(input('enter n:'))
x= [[a,b,c] for a in range(1,n) for b in range(a,n) for c in range(b,n) if c*c==a*a+b*b]
print(x)






