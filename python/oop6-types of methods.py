# 1)instance method
# 2)class methods  -- decorators
# 3) static methods-- --||--    ie. @classmethod, @staticmethods 
#1)
class demo:
    def a(self):          #requires self
        print('method a')

    @classmethod            #can work with both both class as well as instance members
    def b(self):
        print('method b')

    @staticmethod           # works only with static members
    def inttobin(x):
        a=[]
        while x >0:
            a.append(x%2)
            x//=2
        return a[::-1]    

r1=demo()

r1.a()
r1.b()             #}_ #can be called as demo.b() demo.c()
a=r1.inttobin(10)  #}
print(a)
