def cross_pattern(n):
    for i in range(1,n+1):
        print(' '*(i-1),end='')
        print('*',end='')
        print(' '*(n-i)*2,end='')
        print('*',end='')
        print()
    for i in range(1,n+1):
        print(' '*(n-i),end='')
        print('*',end='')
        print(' '*(i-1)*2,end='')
        print('*',end='')
        print()
    '''
    5
    *        *
     *      *
      *    *
       *  *
        **
        **
       *  *
      *    *
     *      *
    *        *
    '''

def kite_pattern(n):
    for i in range(1,n+1):
        print(' '*(n-i),end='')
        print('*',end='')
        print(' '*(i-1)*2,end='')
        print('*',end='')
        print()
    for i in range(1,n+1):
        print(' '*(i-1),end='')
        print('*',end='')
        print(' '*(n-i)*2,end='')
        print('*',end='')
        print()
    '''
    5
        **
       *  *
      *    *
     *      *
    *        *
    *        *
     *      *
      *    *
       *  *
        **
    '''    
def sandclock_pattern(n):
    for i in range(1,n+1):
        print(' '*(i-1),end='')
        print('*'*(n-i+1)*2,end='')
        print()
    for i in range(1,n+1):
        print(' '*(n-i),end='')
        print('*'*(i)*2,end='')
        print()
    '''
    5
    **********
     ********
      ******
       ****
        **
        **
       ****
      ******
     ********
    **********
    '''

if __name__=="__main__":
    n = int(input())
    #cross_pattern(n)
    #kite_pattern(n)
    sandclock_pattern(n)
    
    

    
