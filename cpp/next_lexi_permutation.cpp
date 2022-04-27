// https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/

// Logic:
// intutiion - items are always in increasing order from right to left eg: 1 2 5 4 3 , 5>4>3
// find the item that doesnot follow increasing order from right. (in this case 2, since 2< 5>4>3)
// then swap 2 with closest greater element than 2 (int this case 3) (mostly the last element since array is alwats in increasing order)
// Now the arr is (1,3,5,4,2)
// then sort the array from right of 2 till end. (i.e reverse the array since its already sorted in descending order)
// op->(1,3,2,4,5)


#include<bits/stdc++.h>
using namespace std;

void swap(int *arr,int i, int j){
    arr[i] = arr[i] + arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] = arr[i] - arr[j]; 
}

void reverse(int *arr,int i,int j){
    while(i<j){
        swap(arr,i,j);
        i++;j--;
    }
}

void next_permutation_1(int *arr, int n){
    int i = n-1;
    while(i>=0){
        if(arr[i] > arr[i-1]){
            i--;break;
        }
        i--;
    }

    if(i<0){
        reverse(arr,0,n-1);
    }
    else{
        swap(arr,i,n-1);
        reverse(arr,i+1,n-1);
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,5,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // next_permutation(arr,arr+5); //using in-built function of C++
    next_permutation_1(arr,n);
    
    for(int k:arr){
        cout<<k<<" ";
    }

    return 0;
}
