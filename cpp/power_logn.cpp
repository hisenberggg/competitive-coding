#include<bits/stdc++.h>
using namespace std;

double power(double x, int n){
    cout<<"n is "<<n<<endl;
    if(n==0)
        return 1;

    if(n==1) 
        return x;
        
    if(n==-1)
        return 1/x;

    int mid = n/2;
    // cout<<"mid is "<<mid<<endl;
    if(n>0){
        if(n%2==1)
            return power(x,mid)*power(x,mid+1);
        else
            return power(x,mid)*power(x,mid);
    }
    else{
        if(abs(n)%2==1)
            return power(x,mid)*power(x,mid-1);
        else
            return power(x,mid)*power(x,mid);
    }
}

int main(int argc, char const *argv[])
{
    double x = 12.3053;
    int n = -3;
    cout<<x<<" raised to "<<n<<" is :"<<power(x,n);
}

