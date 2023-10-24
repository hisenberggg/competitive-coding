#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s = "s";
    s = "p" + s;
    cout << s[s.length()-1];
    s.pop_back();
    // cout << k;
    return 0;
}
