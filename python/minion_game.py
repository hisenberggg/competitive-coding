def minion_game(s):
    st=0
    ke=0
    l=len(s)
    for i in range(len(s)):
        if s[i] in "AEIOU":
            ke+=l-i
        else:
            st+=l-i
    if ke>st:
        print("Kevin",ke)
    else:
        print("Stuart",st)

if __name__ == '__main__':
    s = input()
    minion_game(s)
