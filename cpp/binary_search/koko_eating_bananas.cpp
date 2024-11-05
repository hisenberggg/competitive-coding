#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h){
    int n = piles.size();
    int max_pile = 0;
    for(auto it:piles){
        max_pile = max(max_pile,it);
    }

    int left = 1, right = max_pile;
    while(left<=right){
        int mid = left + (right-left)/2;
        int maxtime = h;
        bool is_enough = true;
        for(int i=0;i<n;i++){
            int x = ceil((float)piles[i]/mid);
            maxtime -= x;
            if(maxtime<0){
                is_enough = false;
                break;
            }
        }
        if(left==right){
            return left;
        }
        else if(is_enough){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    vector<int> piles = {3,6,7,11};
    int h = 8;

    int k = minEatingSpeed(piles,h);
    cout<<"Minimum eating speed req: "<<k;
    return 0;
}
