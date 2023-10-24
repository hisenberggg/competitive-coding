#include<bits/stdc++.h>
using namespace std;
string decrypt(string word, int n){
    string op = "";
    int temp;
    if(word.size() == 0){
        return op;
    }
    for(int i=0;i<n;i++){
        if(i==0){
            if(word[i]=='a') op += 'z';
            else op += word[i]-1;
        }
        else{
            temp = (int)(word[i] - word[i-1]);
            while(temp<97){
                temp += 26;
            }
            op += (char)temp;
        }
    }
    return op;
}

int main(){
    string a = "flgxswdliefy";
    cout<<decrypt(a,a.size());
    return 0;
}