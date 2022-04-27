'''
#oop3-constructors/initializer

class demo:
    def demo():        #just a normal function
        pass

    def __init__(self):
        print('demo obj')
    def xy(self):
        print('demo xy')

r=demo()
r.xy()
r.demo()
'''
#constructor overloading

class rectangle:
    def __init__(self,ln,br=None):
        if br is None:
            self.length=self.breadth=ln
        else:
            self.length=ln
            self.breadth=br
    def area(self):
        a=self.length*self.breadth
        return a

    def __demo(self):          
        print('hello')


r1=rectangle(10,5)
print('area=',r1.area())
r2=rectangle(8)
print('area for sqr=',r2.area())
print(r1.length,r1.breadth)
r1.demo()
