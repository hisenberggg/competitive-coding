#include<bits/stdc++.h>
using namespace std;

int get_max_area_3N(vector<int> &heights){
    int n = heights.size();
    vector<int> lse(n,0);     //left smaller element
    vector<int> rse(n,n-1);   //right smaller element

    stack<int> stk;
    for(int i=0;i<n;i++){
        while(!stk.empty() && heights[stk.top()]>=heights[i]){
            stk.pop();
        }
        if(!stk.empty()){
            lse[i] = stk.top()+1;
        }
        stk.push(i);
    }

    stack<int> stk1;
    for(int i=n-1;i>=0;i--){
        while(!stk1.empty() && heights[stk1.top()]>=heights[i]){
            stk1.pop();
        }
        if(!stk1.empty()){
            rse[i] = stk1.top()-1;
        }
        stk1.push(i);
    }

    cout<<"lse: ";
    for(auto it:lse)
        cout<<it<<" ";
    cout<<endl;

    cout<<"rse: ";
    for(auto it:rse)
        cout<<it<<" ";
    cout<<endl;

    int max_area = INT_MIN;
    for(int i=0;i<n;i++){
        int area = (rse[i] - lse[i] + 1) * heights[i];
        max_area = max(max_area,area);
    }

    return max_area;
}

int get_max_area_single_pass(vector<int> &heights){
    int n = heights.size();
    stack<int> stk;
    int maxarea = 0;

    // go till n...since we get the 'right smaller' first while traversing 
    for(int i=0;i<=n;i++){

        // enter the while loop (to compute area of prev) if
        // 1. any prev element is there in stack && current element (i) is less than stack top (make increasing stack)
        // 2. last element is passed and still prev elements are left to compute area 
        while((!stk.empty() && heights[stk.top()]>heights[i]) || (i==n && !stk.empty())){
            int curr = stk.top();     //element to compute area
            int rightsmaller = i;     //right smaller is current (that's why it entered this loop)
            stk.pop();        

            int leftsmaller = -1;    //mark to -1 in case stk is empty
            if(!stk.empty()){
                leftsmaller = stk.top(); //left smaller is the one below current compute element (since it is increasing stack)
            }
            int area = (rightsmaller-leftsmaller-1) * heights[curr]; // -1 should be done to get the middle area
            maxarea = max(maxarea,area);
        }

        stk.push(i); //finally push every element to stack (for computing area)
    }

    return maxarea;
}


int main(){
    vector<int> heights = {1, 0, 1, 2, 2, 2, 2, 1, 0, 2};
    // vector<int> heights = {3,1,5,6,2,3};
    
    // int max_area = get_max_area_3N(heights);
    int max_area = get_max_area_single_pass(heights);
    cout<<"MAX area is: "<<max_area;

    return 0;
}