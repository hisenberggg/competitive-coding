#include<bits/stdc++.h>
using namespace std;

double power(double x, int n){
    int nn = n;
    long long ans = 1;
    while(nn>0){
        if(nn%2){
            ans *= x;
            nn -= 1;
        }
        else{
            x = x*x;
            nn /= 2;
        }
    }
    return n>0?ans:1/ans;
}

// using recursion 
long long helper(double x, int n){
    if(n == 0) return 1;
    if(x == 0) return 0;

    long long ans = helper(x*x,n/2);
    return n%2 ? x*ans : ans;
}
double power_recursion(double x, int n){
    return n>0 ? helper(x,n): 1/helper(x,n);
}


int main(int argc, char const *argv[])
{
    double x = 3;
    int n = 3;
    cout<<x<<" raised to "<<n<<" is :"<<power_recursion(x,n);
}

