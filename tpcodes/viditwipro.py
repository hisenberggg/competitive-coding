n = int(input())
a = [int(i) for i in input().split()]
i = max(a)
a.remove(i)
j = max(a)
print(i+j)
