n = int(input())
for n_t in range(n):

    a = list(map(int,input().strip().split()))

    if len(set(a)) == 4 or len(set(a)) == 3 :
        print("2")
    elif len(set(a)) == 2:
        print("1")
    else:
        print("0")
