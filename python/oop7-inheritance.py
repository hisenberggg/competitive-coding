#inheritance
'''
supports multiple inheritance

'''
class demo:
    def a(self):
        print('demo a')
        self.m=100
    def __init__(self):
        print('demo-default')
        

class demo2(demo):
    def b(self):
        print('demo2')
        print('m= ',self.m)
    def a(self):                    #method overriding
        print('demo2-a')
        super().a()

    def __init__(self):             #this constructor overrides super class constructor 
        
        print('demo2-default')
        super().__init__()        #can be the second statement unlike java
        
    '''def a(self,n):                    #if paramters are changed ..still the method is overridden instead of overloading
        print('demo2-a')
        super().a()'''
        
r1=demo2()
#r1.b()            err since m is nt declare/assigned value / created yet
r1.a()
r1.b()
print('m= ',r1.m)
print('MRO:',demo2.mro())

        
