
#include <bits/stdc++.h>
#include<iostream>

using namespace std;

bool compare(int one[26],int two[26]){
        int i=0;
        while(i<26){
            if(one[i] != two[i]){
                return false;
            }
            i++;
        }
        return true;
    }
void getEmbeddings(string s,int a[],int i,int j){
    while(i<=j){
            a[s[i]-'a']++;
            i++;
        }
    }

int main(){
    int one[26]={0},two[26]={0},i=0,j;
    string s1="ab",s2="idebaooo";

    getEmbeddings(s1,one,0,s1.length()-1);
        
    i=0,j=s1.length()-1;

    while(j < s2.length()){
        getEmbeddings(s2,two,i,j);
        cout<<i<<" "<<j<<endl;
        if(compare(one,two)){
            cout<<"True"<<endl;
            break;
        }
        for(int k=0;k<26;k++)
            two[k] = 0;
        j++;i++;
    }
    cout<<"False"<<endl;

    return 0;
}
