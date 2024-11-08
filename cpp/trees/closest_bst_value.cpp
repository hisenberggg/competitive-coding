#include<bits/stdc++.h>
using namespace std;
// TreeNode class
class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    // Constructor
    TreeNode(int val){
        this->val=val;
        left=right=NULL;
    }
};

// write your functions here 
void closest_value(TreeNode* root, double target, int& mini, double mindiff){
    if(root==NULL)
        return;

    double diff = abs((float)root->val - target);
    cout<<diff<<endl;

    if(diff<mindiff || (diff == mindiff && root->val < mini)){
        mindiff = diff;
        mini = root->val;
    }
    if(target<root->val){
        closest_value(root->left,target,mini,mindiff);
    }
    else if(target>root->val){
        closest_value(root->right,target,mini,mindiff);
    }
}

int main(){

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);


    // call your functions here 
    double target = 3.714286;
    int mini = root->val;
    double mindiff = INT_MAX;
    closest_value(root,target,mini,mindiff);

    cout<<"output"<<mini<<endl;

    return 0;
}