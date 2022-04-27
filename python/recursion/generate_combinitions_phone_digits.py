

def print_words(dic,inp,op,index):

    # if current index is equal to given input's(array) length
    # print coz it is req length of op &
    #need to break else list out of bounds error
    if len(inp) == index:
        print(op,count)
        return

    # go to next digit for iteration over its length 
    digit = inp[index]

    # dont include in op if digit is 0 or 1
    if digit == 0 or digit == 1:
        print_words(dic,inp,op,index+1,count+1)
    else:
        #iterate over the length of digit
        '''
        23
        2 = abc; 3 = def
            2      
        a   b   c
        def def def

        '''
        num_len = len(dic[digit])
        for i in range(num_len):
            print_words(dic,inp,op+dic[digit][i],index+1)

if __name__=='__main__':
    dic = {
              0:'',
              1:'',
              2:'abc',
              3:'def',
              4:'ghi',
              5:'jkl',
              6:'mno',
              7:'pqrs',
              8:'tuv',
              9:'wxyz'
          }
    inp = [2,3,4]
    op = ''
    index = 0
    count = 0
    print_words(dic,inp,op,index)
