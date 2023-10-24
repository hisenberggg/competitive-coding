#include<bits/stdc++.h>
using namespace std;

int main(){
    int A[] = {-13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6}; 
    int K = 15;
    int N = sizeof(A)/sizeof(int);
    int sum = 0, front = 0, max_length = INT_MIN;

    for(int i=0; i<N; i++){
        while(sum > K && front < i){
            sum -= A[front];
            front++;
        }
        if(sum == K){
            max_length = max(i-front,max_length);
        }
        sum += A[i];
        cout<<sum;
    }
    cout<<max_length;
    return 0;
}