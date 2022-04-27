'''
#inefficient
T- O(n^3)
str = input()

max_length = 0
word1 = ""
for i in range(len(str)):
    for j in range(i+1, len(str)+1):
        word = str[i:j]
        if (word == word[::-1]):
            if max_length < len(word):
                max_length = len(word)
                word1 = word
print(word1)
'''

#T: O(n^2)  S: O(1)

def longestPalinSubs(s):
    start = 0
    end = 0

    for i in range(len(s)):

def plaindrome(s,left,right):
    if len(s)==0 or s==None:
        return 0
    while left>=0 and right <len(s) and s[left]==s[right]:
        left-=1
        right+=1
    return right - left

            
        

