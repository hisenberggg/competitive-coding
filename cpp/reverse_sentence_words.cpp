#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string a = "This is a string";
    string temp = "", ans = "";
    int left = 0, right = a.length();
    while(left <= right){
        if(a[left] != ' '){
            temp += a[left];
        }
        else if(a[left] == ' '){
            if(ans == ""){
                ans += temp;
            }
            else{
                ans = temp + " " + ans; 
            }
            temp = "";
        }
        left++;
    }
    ans = temp + " " + ans;
    cout<<ans;
    return 0;
}
