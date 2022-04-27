#Destructor- object clearing or any recource opened by object ..lyk database etc...
#task: maintain count even after obj is deleted  & create new obj var according to count

class demo:
    s1=0                
    i=1
    def __init__(self):
        demo.s1+=1
        self.y=demo.i
        demo.i+=1
        print('constructor')
    
    def x(self):
        print('no=',self.y)
        
    def count(self):
        print('count=',demo.s1)

    def __del__(self):
        demo.s1-=1
        print('object destroyed',self.y)



r1=demo()
r2=demo()
r2.x()
del(r2)
r3=demo()
r3.count()

