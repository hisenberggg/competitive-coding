#exceptions
#syntayx: except exc_name as name:
print('program starts')
try:
    a=[5,30,0,'xy',7]
    i=int(input('enter index: '))
    print('value =',a[i])
    d=a[i]/a[i+1]
    print('ans= ',d)
except ZeroDivisionError as ze:
    print('err-division by zero ',ze)

except TypeError as te:
    print('type error ',te)    

except Exception as ex :
    print('error occured ',ex)

else:
    print('no error')
finally:
    print('this is finally')

print('--program ended--')
'''
try
except - if error occurs
else - if no error
finally - code that always works
'''
