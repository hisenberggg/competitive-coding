#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 3, -2, 4};
    int n = arr.size();

    // max positive product
    // ending at the current position
    int max_ending_here = arr[0];
 
    // min negative product ending
    // at the current position
    int min_ending_here = arr[0];
 
    // Initialize overall max product
    int max_so_far = arr[0];
    /* Traverse through the array.
    the maximum product subarray ending at an index
    will be the maximum of the element itself,
    the product of element and max product ending previously
    and the min product ending previously. */
    for (int i = 1; i < n; i++)
    {
        cout<<max_ending_here<<" "<<min_ending_here<<" "<<max_so_far<<endl;
        int temp = max({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        min_ending_here = min({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        max_ending_here = temp;
        max_so_far = max(max_so_far, max_ending_here);
    }
    cout<<max_so_far;
    return 0;
}
