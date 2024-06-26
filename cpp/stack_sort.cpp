#include<bits/stdc++.h>
using namespace std;

// using resursion for inserting element 
void stack_insert(stack<int> &stk,int n){
    if(stk.empty()){
        stk.push(n);
        return;
    }
    int temp = stk.top();
    if(temp>n){
        stk.pop();
        stack_insert(stk,n);
        stk.push(temp);
    }
    else{
        stk.push(n);
        return;
    }
}

void stack_sort_rec(stack<int> &stk){
    if(stk.empty()){
        return;
    }

    int temp = stk.top();
    stk.pop();
    stack_sort_rec(stk);

    stack_insert(stk,temp);
}
/////////////////////////////////////////

// using while loop for inserting in stack 
void stack_sort(stack<int> &stk){
    if(stk.empty()){
        return;
    }

    int num = stk.top();
    stk.pop();
    stack_sort(stk);

    stack<int> temp;
    while(!stk.empty() && stk.top()>num){
        temp.push(stk.top());
        stk.pop();
    }
    stk.push(num);
    while(!temp.empty()){
        stk.push(temp.top());
        temp.pop();
    }
}
///////////////////////////////

int main(){
    stack<int> stk;
    stk.push(4);
    stk.push(3);
    stk.push(1);
    stk.push(5);
    stk.push(2);
    
    // stack_sort(stk);

    stack_sort_rec(stk);

    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }

    return 0;
}