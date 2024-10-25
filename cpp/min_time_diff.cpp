#include<bits/stdc++.h>
using namespace std;

int convert(string s){
    int hr = stoi(s.substr(0,2));
    int min = stoi(s.substr(3,2));

    return hr*60 + min;
}

int main(int argc, char const *argv[])
{
    vector<string> timePoints = {"23.59","00:00"};
    int n = timePoints.size();
    
    vector<int> minutes;
    for(auto it:timePoints){
        minutes.push_back(convert(it));
    }
    sort(minutes.begin(),minutes.end());
    int mindiff = INT_MAX;
    int prev = minutes[minutes.size()-1];
    for(auto it:minutes){
        int diff = abs(it - prev);
        mindiff = min(mindiff,diff);

        diff = abs(it - prev);
        mindiff = min(mindiff, 1440 - diff);

        prev = it;
    }
    cout<<mindiff;
    return 0;
}
