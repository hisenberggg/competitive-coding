                    #OOP:
class demo:
    ''' class to add to nos '''
    def inputdata(self):
        self.a=int(input("Enter no1"))
        self.b=int(input("Ente no2"))
    def add(self):
        return self.a+self.b
    def f(self):
        print('m=',self.m)
    


r =demo()
r.inputdata()        # r itself goes as a parameter to inputdata function
print('sum :',r.add())
print(r)
print(demo.__doc__)
print(r.__dict__)
r.m=10              #dynamically added to class's object
r.f()
