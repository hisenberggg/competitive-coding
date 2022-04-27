// https://www.youtube.com/watch?v=wT7gcXLYoao

// n = 3, k = 4
// keeping 1st constant rest can be arranged in (n-1)! ways
// 123
// 132
// 213
// 231
// 312
// 321

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4, k = 15, fact = 1;
    vector <int> a;
    for(int i=1;i<n;i++){
        fact*=(i);
        a.push_back(i);
    }
    a.push_back(n);
    k--;

    string op="";
    while (true)
    {
        op += to_string(a[k/fact]);

        a.erase(a.begin()+k/fact);

        if(a.size() < 1) break;

        k = k % fact;
        fact = fact/a.size();
    }

    cout<<op;

    return 0;
}
