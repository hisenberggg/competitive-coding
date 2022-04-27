
'''
a=10
b=10
print(id(a),id(b))
a+=5
print(id(a),id(b))
c=[1,2,3]
print(id(c[0]),id(c[1]))
'''
'''
def demo(a,b):

//vars are passes as call-by-value eg int,float
    a+=1
    b+=1
    print('inside function :',a,b,id(a),id(b))

x=5
y=10
demo(x,y)
print('values after demo :',x,y,id(x),id (y))
y=6
print(id(y))
'''

'''
def demo1(a):
    a[0]+=1
    a[1]+=1
    a[2]+=1
    print(a)

b=[5,10,15]
print(id(b[0]),id(b[1]))
demo1(b)
print('after fn =',b)
'''

g1=10
def demo1(x):
    a=10
    print(a,x,g1)
def demo2(y):
    #global g1          #if you want to edit globel var then write 'globel' keyword
    a=2
    b=5
    g1=a+y
    #g1=g1+y           #if globel is written then it will edit globel var else it is error
    print(a,b,g1)
print(g1)
demo2(5)
demo1(10)
print(g1)









    


    
    
