'''def add(a,b):
    return a+b,a-b
x,y=add(2,3)
#print(add(2,3))
print(x,y)
c=add(2,3)                   #returns tuple
print(c)

#1)default param fn
def interest(p,n,r=10):      #default params should be on right-most side
    return p*n*r/10
print(interest(1000,2))
print(interest(1000,2,5))

#2)key word args
i=interest(r=2,p=2000,n=3)

def y(b):
    return lambda a:a+b
x=y(2)
print(x(3))
'''
'''
#def demo(**data,a):         #error
#def demo(a,**data):         #valid

def demo(**data):#received as a dictionary
    print(data,a)
    data['r']+=5
    print(data)
demo(r=1,n=3)


#3)variable length args
def add(*val):              #gets vals in tuple 
    s=0
    if len(val)>0:
        for i in range(len(val)):
            s+=val[i]
    return s
def add1(*val):
    s=0
    if len(val)>0:
        for v in val:
            s+=v
    return s            
def add2(*val):
    s=0
    if len(val)>0:
        return sum(val)
    return s
print(add(1,2,3,4))
print(add1(1,2,3,4))
print(add2(1,2,3,4))
'''
'''
#4)Closure -function inside a function
                                        #inner funcn can use vars of outer funcn but outer funcn cant use vars of inner funcn
                                        #only outer function can be called
def interest(p,n):
    def rate(amt):
        if amt >= 100000:
            return 10
        elif amt >=50000:
            return 7
        else :
            return 5
    si=p*n*rate(p)
    return si
a,y=[int(input('enter amt')),int(input('enter years'))]
print(interest(a,y))
'''
list=[1,2,3,4,5,6,7]
def a(list):
    def v():
        s=0
        for i in list:
            s+=i
        return s/len(list)
    def l(avg):
        lr=0
        for i in list:
            if i>avg:
                lr+=1
        return lr
    def s(avg):
        sm=0
        for i in list:
            if i<avg:
                sm+=1
        return sm
    avg=v()
    return l(avg),s(avg)
print(a(list))    



