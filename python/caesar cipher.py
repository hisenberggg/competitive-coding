def cipher(s,k):
    new=''
    for i in s:
        c = ord(i)-ord('A')+1
        c1= (c+k) % 26
        c2= chr(c1+ord('A'))
        new+=c2
    return new    
def op_s(s,s1):
    op=''
    for i in range(len(s)):
        if s[i].isupper():
            op+=s1[i].upper()
        else:
            op+=s1[i].lower()
    return op        
        
while True:
    print('__Select any option__\n1- caesar cipher encryption\n2- caesar cipher decryption\n3- k- encryption\n4- k-decryption\n5- Exit')
    n=int(input())
    if n in [1,2,3,4]:
        s=input('Enter the input string: ')
    if n==1:
        k=3
        s1=cipher(s.upper(),k-1)
    elif n==2:
        k=-3
        s1=cipher(s.upper(),k-1)
    elif n==3:
        k=int(input('Enter value of k: '))
        s1=cipher(s.upper(),k-1)
    elif n==4:
        k=-int(input('Enter value of k: '))
        s1=cipher(s.upper(),k-1)
    elif n==5:
        break
    else:
        print('INVALID\n')
        continue
    print('___OUTPUT: '+op_s(s,s1)+' ___\n')

