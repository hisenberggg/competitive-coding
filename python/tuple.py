

#non editable collection of any type
a=(5,15,"ab",[5,7.3],2.5)
print(a)
for i in a:
    print(i)
#err
a[0]="ab"
print(a)
