import itertools
n=int(input()) # number of iterations
for i_n in range(n):
    k=int(input()) # number of elements
    sequence = [int(i) for i in input().split()] #list of input
    s=int(input())   #the sum you want
    c=0
    for i in range(len(sequence)):
        for j in itertools.combinations(sequence, i):
            print(j)
            if sum(j)==s:
                c+=1
                print(j,sum(j))
    print(c)
