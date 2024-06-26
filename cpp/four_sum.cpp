#include<bits/stdc++.h>
#include<string>
using namespace std;


int four_sum(vector<int>& arr, int target, int n){
    int count  = 0;

    for(int i=0;i<n-3;i++){
        int curr_target1 = target - arr[i];
        cout<<"Curr target 1: "<<curr_target1<<endl;
        
        // three sum after this //
        for(int j=i+1;j<n-2;j++){

            int curr_target2 = curr_target1-arr[j];
            cout<<"\t* Curr target 2: "<<curr_target2<<endl;

            // two sum after this //
            set<int> s;
            for(int k=j+1;k<n;k++){
                int required_target = curr_target2 - arr[k];
                cout<<"\t\t* Req target: "<<required_target<<endl;
                if(s.find(required_target) != s.end()){
                    count++;
                    cout<<"\t\t- "<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<<required_target<<"\n";
                }
            s.insert(arr[k]);
            }     
            // == //       
        }
        // === //
    }

    return count;
}

int main(){
    int target = 8;
    vector<int> arr = {2,2,2,2,1,3};
    int n = arr.size();

    int total_count = four_sum(arr,target,n);

    cout<<"Total quadraplets with target '"<<target<<"' are: "<<total_count;
}