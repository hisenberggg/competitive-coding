#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& a,int i,int j){
    int t;
    while(i<j){
        t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;j--;
    }
}

int main()
{
    vector<int> nums;
    int k = 3;
    for(int i=0;i<=1;i++){
        nums.push_back(i);
    }
    cout<<"input:";
    for(int i = 0;i<nums.size()-1;i++)
        cout<<nums[i];
    cout<<endl;
    reverse(nums,0,nums.size()-k-1);
    reverse(nums,nums.size()-k,nums.size()-1);
    reverse(nums,0,nums.size()-1);
    cout<<"Output:";
    for(int i = 0;i<nums.size()-1;i++)
        cout<<nums[i];
    return 0;
}
