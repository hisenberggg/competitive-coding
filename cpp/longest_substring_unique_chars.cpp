
#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    string s = "abcdefg";
    int maxi=1,u=0,v=0;
        set<char> a;
        cout<<s.length()<<endl;
        for(int i=0;i<s.length();i++){
            if(a.count(s[i]) == 1){
                cout<<"inside exists"<<endl;
                u++;
                if(maxi<a.size()){
                    maxi = a.size();
                }
                a.clear();       
            }
            a.insert(s[i]);
        }
    cout<<"ans: "<<maxi<<endl;
    return 0;
}