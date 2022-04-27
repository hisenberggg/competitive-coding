
#class variable / static variable

class demo:
    s1=0            #static/class can be used to keep count or remember no of object    

    def __init__(self):
        demo.s1+=1       #**IMP : if written as self.s1 then a new variable will be created ..so compulsory write class_name.classvar_name 
        self.y=self.s1
    
    def x(self):
        print('no=',self.y)
        
    def count(self):
        print('count=',demo.s1)
r1=demo()
r2=demo()
r3=demo()
r4=demo()
r5=demo()

r5.count()
r3.x()
r4.x()
