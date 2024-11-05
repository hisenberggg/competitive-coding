#include<bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2){
    int n = num1.size();
    int m = num2.size();

    vector<int> output(n+m,0);
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            output[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
            output[i+j] += output[i+j+1]/10;
            output[i+j+1] = output[i+j+1]%10;
        }
    }
    string ans = "";
    int i=0;
    while(output[i]==0) i++;
    while(i<n+m){
        ans += to_string(output[i]);
        i++;
    }
    return ans;
}

int main()
{
    string num1 = "12";
    string num2 = "12";

    string output = multiply(num1, num2);
    cout<<output;
    return 0;
}
