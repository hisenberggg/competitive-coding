#include<bits/stdc++.h>
#include<string>
using namespace std;


int three_sum_better(vector<int>& arr, int target, int n){
    int count  = 0;

    for(int i=0;i<n-2;i++){
        int curr_target = target - arr[i];
        cout<<"Curr target: "<<curr_target<<endl;

        // two sum after this //
        set<int> s;
        for(int j=i+1;j<n;j++){

            int required_target = curr_target-arr[j];
            cout<<"\t* req target: "<<required_target<<endl;
            if(s.find(required_target) != s.end()){
                count++;
                cout<<"\t\t- "<<arr[i]<<" "<<arr[j]<<" "<<required_target<<"\n";
            }
            s.insert(arr[j]);
        }
        // === //
    }

    return count;
}

int three_sum_optimal(vector<int> arr, int n, int K){
	vector<vector<int>> output;
    int count = 0;

	sort(arr.begin(),arr.end());

	for(int i=0;i<n;i++){
		int j = i+1;
		int k = n-1;

		while(j<k){
			int sum = arr[i] + arr[j] + arr[k];
			if(sum > K){
				k--;  //reducing the sum
			}
			else if(sum < K){
				j++;  //increasing the sum
			}
			else{
				count++;
                cout<<"- "<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"\n";
				j++;
				k--;
				// skip duplicates 
				while(j<k && arr[j] == arr[j-1]) j++;				
				while(j<k && arr[k] == arr[k+1]) k--;
			}
		}
		// skip duplicates 
		while(i<n-1 && arr[i] == arr[i+1]) i++;
	}
	return count;
}

int main(){
    int target = 12;
    // vector<int> arr = {11,3,6,2,5};
    vector<int> arr = {10,5,5,5,2};
    int n = arr.size();

    // int count = three_sum_better(arr,target,n);
    int count = three_sum_optimal(arr,n,target);

    cout<<"Total triplets with target '"<<target<<"' are: "<<count;
}