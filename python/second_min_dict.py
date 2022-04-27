if __name__ == '__main__':
    def get_key(val,my_dict):
        k=[]
        for key, value in my_dict.items():
            if val == value:
                k.append(key)
        return k
    
    d={}
    for _ in range(int(input())):
        name = input()
        score = float(input())
        d[name]=score

    a={k: v for k, v in sorted(d.items(), key=lambda item: item[1])}    
    m=min(list(a.values()))
    s=list(a.values())[list(a.values()).count(m)]
    [print(i) for i in sorted(get_key(s,d))]
