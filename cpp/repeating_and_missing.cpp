#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,3,4,5,5,6};
    int n = 6;

    int sum_og, sum_calc = arr[0];
    pair<int,int> output;
    int repeating;

    for(int i=1;i<n;i++){
        sum_calc += arr[i];
        if(arr[i]==arr[i-1]) repeating = arr[i];
    }
    sum_calc -= repeating;
    sum_og = (n*(n+1))/2;

    output.first = sum_og-sum_calc;
    output.second = repeating;

    cout<<output.first<<" "<<output.second<<endl;

    return 0;
}
