#include<bits/stdc++.h>
using namespace std;

int calculate(string s){
    int n = s.size();
    char sign = '+';
    int num = 0;
    stack<int> stk;

    for(int i=0;i<n;i++){
        char ch = s[i];

        if(isdigit(ch)){
            num = num*10 + (ch-'0');
        }

        if(i==n-1 || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            if(sign=='+'){
                stk.push(num);
            }
            else if(sign=='-'){
                stk.push(-num);
            }
            else if(sign=='*'){
                int temp = stk.top();
                stk.pop();
                stk.push(temp*num);
            }
            else if(sign=='/'){
                int temp = stk.top();
                stk.pop();
                stk.push(temp/num);
            }
            sign = ch;
            num = 0;
        }
    }

    int output;
    while(!stk.empty()){
        output += stk.top();
        stk.pop();
    }
    return output;
}

int main(int argc, char const *argv[])
{
    string s = "3*2+1";
    int output = calculate(s);
    cout<<"value of "<<s<<" is: "<<output;
    return 0;
}
