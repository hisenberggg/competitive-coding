#include<bits/stdc++.h>
using namespace std;

bool isStrobogrammaticNumber(string num){
    vector<int> water_image = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
      
    // Initialize two pointers, one starting from the beginning (left) and the other from the end (right) of the string
    int left = 0, right = num.size() - 1;
    
    // Loop through the string with both pointers moving towards the center
    while (left <= right) {
        // Convert characters to their corresponding integer values
        int left_digit = num[left] - '0';
        int right_digit = num[right] - '0';
        
        // Check if the current digit has a valid strobogrammatic counterpart
        // and whether it matches the counterpart of its mirror position
        if (water_image[left_digit] != right_digit) {
            // If not, then the number isn't strobogrammatic
            return false;
        }
        
        // Move the pointers towards the center
        ++left;
        --right;
    }
    
    // All checks passed, the number is strobogrammatic
    return true;
}

int main()
{
    string s = "";
    cout<<(isStrobogrammaticNumber(s)?"true":"false");
    return 0;
}
