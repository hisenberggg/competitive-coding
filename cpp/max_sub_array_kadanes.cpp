#include<bits/stdc++.h>
using namespace std;

int max_arr_sum(vector<int>& a, vector<int>& subarray){
    int mst = a[0], mlt = 0, s = 0;
    for(int i = 0;i<a.size();i++){
        mlt += a[i];
        if(mst<mlt){
            subarray.clear();
            mst = mlt;
            subarray.push_back(s);
            subarray.push_back(i);
        }
        if(mlt<0){
            s = i + 1;
            mlt = 0;
        }
    }

    return mst;
}

int main()
{
    vector<int> arr = {-1,0,1,2};
    vector<int> subarray;

    int op = max_arr_sum(arr,subarray);
    cout<<"Max sum:"<<op<<"\n";
    cout<<"Contigious elements with max sum:";
    for(int i = subarray[0]; i <= subarray[1]; i++){
        cout<<arr[i]<<" ";
    }
}
