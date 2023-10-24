#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d, ca, s, m;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;

    ca = (b+d)/60;
    s = (b+d)%60;
    m = (a+c+ca)%24;

    string mm="",ss="";

    if(s<=9){
         ss += "0"+to_string(s);
    }
    else{
         ss += to_string(s);
    }
    if(m<=9){
         mm += "0"+to_string(m);
    }
    else{
         mm += to_string(m);
    }

    cout<<mm<<" "<<ss<<"\n";

    return 0;
}
