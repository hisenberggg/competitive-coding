def sumBeautifulNumbers (Q, queries):
    sum_queries = []
    for num in queries:
        sum1 = 0
        sum1=[i**3 for i in range(num[0], num[1]+1) if str(bin(i).lstrip("0b")).count("0")>=1 and str(bin(i).lstrip("0b")).count("0")<=3]
        sum_queries.append(sum(sum1)%998244353)
    return sum_queries

Q = int(input())
queries = [list(map(int, input().split())) for i in range(Q)]
out_ = sumBeautifulNumbers(Q, queries)
print (' '.join(map(str, out_)))
#1000000000000000000

def binprint(n):
    c=0
    for i in range(n):
        check = str(bin(i).lstrip("0b"))
        if check.count("0")>=1 and check.count("0")<=3:
            c+=1
            print(c,i,bin(i).lstrip("0b"))
        
#binprint(1000000)
