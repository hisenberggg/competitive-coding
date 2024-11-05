#include<bits/stdc++.h>
using namespace std;

bool comparator(string a, string b){
    if(a+b > b + a) return true;
    return false;
}

string largestNumber(vector<int> nums){
    vector<string> num_str;
    for(auto it:nums){
        num_str.push_back(to_string(it));
    }
    sort(num_str.begin(),num_str.end(), comparator);

    string output = "";
    for(auto it:num_str){
        output += it;
    }
    return output;
}

int main()
{
    vector<int> nums = {3,30,34,5,9};
    string output = largestNumber(nums);
    cout<<"Largest number formed: "<<output;
    return 0;
}
