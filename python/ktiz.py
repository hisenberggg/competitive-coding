s= int(input())
for s_i in range(s):
    k_i=int(input())
    k=input()
    dc=0
    mf=0
    nc=0
    mc=0
    for i in k:
        if i=="-":
            dc+=1
        elif i=="N":
            if mf:
                mc+=int(dc/2)
                mf=0
                nc+=int(dc/2)
            else:
                nc+=dc
            dc=0
        elif i=="M":
            if mf:
                mc+=dc
                # mf=0
                dc=0
            mf=1
        else:
            pass
    nc+=k.count("N")
    mc+=k.count("M")
    # print(nc,mc) 
    if mc>nc:
        print("Mamta")
    elif nc>mc:
        print("Narendra")
    else:
        print("Coalition Government")
