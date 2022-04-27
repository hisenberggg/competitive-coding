                #Strings-object of class 'str'
a="ABCDE"
b="pqr xypq lmn"
c="xyz"
m=b.split()
print(m)
print(len(a))
print(b.count('pq'))
print(c.index('z'))         #if data is not present then gives error
print(c.rindex('z'))        #index of z form right
print(a[1:3])
print(b[1:7:2])


s="hello\nbye\tGN"
print(s)
k=r"hello\nbye\tGN"         # raw string in which spl. chars lyk \n \t are not processed 
print(k)


print('Raje'.istitle())      #1st letter caps indicates title
print('12'.isdigit())
print('aa'.isalnum())
print('sbsbsa'.find('a'))
print('ABfsk'.startswith('AB'))
print('ABfsk'.startswith('sk'))
print(c.upper())
print(a.lower())

c=c.replace('x','p')
print(c)
c+='p'
c=c.replace('p','x',1)
print(c)

s="  jkdd   "
s=s.strip()             #removes spaces from left and right
print('a'+s+'i')
print('a'+'    dhb   '.lstrip()+'a')        #removes left side spaces
print('a'+'    dhb   '.rstrip()+'a')        #removes right side spaces




