'''
#Access specifier- any member with 2 underscore at start are private members
class rectangle:
    def __init__(self,ln,br=None):
        if br is None:
            self.length=self.breadth=ln
        else:
            self.length=ln
            self.breadth=br
        self.__x=25              #private member
    def area(self):
        a=self.length*self.breadth
        return a

    def __demo(self):           #private member     
        print('hello')


r1=rectangle(10,5)
print('area=',r1.area())
r2=rectangle(8)
print('area for sqr=',r2.area())
##print(r1.length,r1.breadth)

r1.demo()                        #demo not found     
print('x=',r1.__x)               # x not found
'''

#class variable / static variable

class demo:
    s1=0                   #class ie static var  ...only static/class vars can be called as classname.varname ie. demo.z1 

    def __init__(self):
        demo.s1+=1
    
    def x(self):
        print('s1=',demo.s1)
        print('s1=',self.s1)
        self.y=10
    def pq(self):
        self.z+=1
r1=demo()
r1.x()
r2=demo()
print(r1.s1)
print(r1.y)
print(demo.s1)

r1.z=100
r1.pq()
print(r1.z)
