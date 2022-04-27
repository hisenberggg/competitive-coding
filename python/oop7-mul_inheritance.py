#multiple inheritance implementation

class demo1:
    def __init__(self):      
        print('demo1-obj')
    def a(self):
        print('demo1_a')

class demo2:
    def __init__(self):
        print('demo2-obj')
    def b(self):
        print('demo2_b')
    def a(self):
        print('demo2-a')

class demo(demo2,demo1):   #sequence of searching anything  is according mentioned in brackets
    def __init__(self):
        print('demo-obj')
        super().__init__()

    def c(self):
        print('demo_c')

r1=demo()    #searches the first init n displays
r1.a()
r1.b()
r1.c()

print('MRO: ',demo.mro())
