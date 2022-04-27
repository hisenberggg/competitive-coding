#Destructor- object clearing or any recource opened by object ..lyk database etc...


class demo:
    s1=0            #static/class can be used to keep count or remember no of object    

    def __init__(self):
        demo.s1+=1
        self.y=self.s1
        print('constructor')
    
    def x(self):
        print('no=',self.y)
        
    def count(self):
        print('count=',demo.s1)

    def __del__(self):                  # destructor: called before destoyed
        print('object destroyed',self.y)

def ab():
    r3=demo()
    print('ab function')

#case 1: object is deleted using del() 
r1=demo()
del(r1)

#case2: when obj is set to none
r2=demo()
r2=None

#case3: when scope of object ends (within a function)
ab()
