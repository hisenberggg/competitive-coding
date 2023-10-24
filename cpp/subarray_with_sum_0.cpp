// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int arr[] = {1,2,0,4,5};
//     int n = sizeof(arr)/sizeof(int);
//     for(int i=0;i<n;i++){
//         int sum = 0;
//         for(int j=i;j<n;j++){
//             sum += arr[j];
//             if(sum == 0){
//                 cout<<"Yes"<<endl;
//             }
//         }
//     }
//     cout<<"No"<<endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];
                if(sum == 0){
                    return "Yes";
                }
            }
        }
        return "No";
    }
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends