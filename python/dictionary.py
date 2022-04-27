#growable and editable collection of key-value pair
name={'a':10.5,'xy':'abcd',25:"abc",26:23}
print(name)
for i in name:
    print(i)
for i in name:
    print(name[i])
name['a']=105
print(name, type(name))
print(name.values())
print(name.keys())
print(name.items())
