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
bool getpath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){ //TC- O(n) SC- O(n)
    if(root==NULL){
        return false;
    }

    path.push_back(root);
    if(root->val == target->val){
        return true;
    }
    
    if(getpath(root->left,target,path) || getpath(root->right,target,path)){
        return true;
    }

    path.pop_back();
    return false;

}


int main(){

    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // call your functions here 
    TreeNode* target = root->left->right->right;
    vector<TreeNode*> path;
    getpath(root, target, path);

    for(auto it:path){
        cout<<it->val<<endl;
    }

    return 0;
}