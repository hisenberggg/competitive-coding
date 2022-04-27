listA=['1','3','2','4','5','3','2','1','4','3','2']
dictA={}

for i in listA:
    if i in dictA.keys():
        dictA[i] += 1
    else:
        dictA[i] = 1
print(dictA)
