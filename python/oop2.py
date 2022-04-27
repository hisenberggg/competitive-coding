                    #OOP:
class demo:
    ''' class to add to nos '''
    def inputdata(s):       #self is not predefined
        s.a=int(input("Enter no1"))
        s.b=int(input("Ente no2"))
    def add(self):
        return self.a+self.b
    def f(self):
        print('m=',self.m)
    def setvals(self,x,y):
        self.a=x
        self.b=y
    def __str__(self):
        s=str(self.a)+','+str(self.b)
        return s
    

'''
r =demo()
r.inputdata()        # r itself goes as a parameter to inputdata function
print('sum :',r.add())
print(r)
print(demo.__doc__)
print(r.__dict__)
r.m=10              #dynamically added to class's object
r.f()
'''
r=demo()
r.setvals(5,10)
print('sum=',r.add()) #--\
                          #==calling bounded method         
y=demo()                 #/
y.setvals(15,7)       #--/
print('sum=',y.add())

print('sum=',demo.add(r))    #calling unbounded method ..here we need to specify parameter to add()
#also
demo.setvals(y,2,3)
print('sum=',y.add())
print('obj=',y)





