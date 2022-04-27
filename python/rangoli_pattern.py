def print_rangoli(size):
    for i in range(size,0,-1):
        print("-"*(i*2-3),end="")
        for j in range(size+1-i):
            if i==1 and j==0:
                print(str(chr(ord('a')+size-j-1)),end="")
            else:
                print("-"+str(chr(ord('a')+size-j-1)),end="")
        for k in range(size-i,0,-1):
            print("-"+str(chr(ord('a')+size-k)),end="")
        print("-"*(i*2-2),end="")    
        print()

    for i in range(1,size):
        print("-"*(i*2-1),end="")
        for j in range(size-i):
            print("-"+str(chr(ord('a')+size-j-1)),end="")
        for k in range(size-i-1,0,-1):
            print("-"+str(chr(ord('a')+size-k)),end="")
        print("-"*(i*2),end="")    
        print()    

        

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)














