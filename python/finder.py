'''a=[(input("Enter/paste a paragraph : ")).split(' ')]
b=[(input("Enter/paste something to search : ")).split(' ')]
'''
a=input("Enter/paste a paragraph : ")
b=input("Enter/paste something to search : ")
'''
c=0
while True:
	try :
		i=a.index(b)
		a=a.replace(b,'',1)
		c+=1
	except:
		if c==0	:
			print('not found')
		else:
			print('found',c,'times')	
		break	
'''
i=-1
c=0
while -1!=(i=a.find(b,i+1)):
	c+=1
print(c)			