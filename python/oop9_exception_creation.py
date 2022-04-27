#Raising an Exception
'''
syntay:

raise ExceptionName(parameter)
                        ^
                        |_=Error message
'''
'''
#catching exception
def multiply(x,y):
    if(x<0 or y<0):
        raise Exception("negative value not allowed")
    else:
        return x*y
try:
    a=int(input('n01:'))
    b=int(input('n02:'))
    ans=multiply(a,b)
    print('Ans: ',ans)
except Exception as ex:
    print('Error:',ex)

print('__prog ends__')    
'''

'''
#creating exception class

class MyException(RuntimeError):
    def msg(self):
        print('negative values not allowed')

def multiply(x,y):
    if(x<0 or y<0):
        raise MyException()     #throws exception at line-39 and program goes in except block
    else:
        return x*y
try:
    a=int(input('n01:'))
    b=int(input('n02:'))
    ans=multiply(a,b)
    print('Ans: ',ans)
except MyException as ex:
    ex.msg()

print('__prog ends__')

'''
#improving creating exception class
class MyException(RuntimeError):
    def __init__(self,s):
        self.errmsg = s

def multiply(x,y):
    if(x<0 or y<0):
        m='values: '+str(x)+','+str(y)
        raise MyException(m) 
    else:
        return x*y
try:
    a=int(input('n01:'))
    b=int(input('n02:'))
    ans=multiply(a,b)
    print('Ans: ',ans)
except MyException as ex:
    print('Error '+ ex.errmsg)

print('__prog ends__')


