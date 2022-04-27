#include<bits/stdc++.h>
using namespace std;

void printPSet(string a, int n){
    
    for(int i = 0; i < (1<<n) ; i++ ){ //i => 0 - 2^n -1
        string s = "";
        for(int j = 0; j < n ; j++){     //j => 0 - n
            if(i & (1<<j) ){
                s += a[j];
            }
        }
        if(s.size() > 0)
            cout<<s<<endl;
    }
}

int main()
{
    string a = "abcd";
    int n = a.size();
    printPSet(a,n);
    return 0;
}

