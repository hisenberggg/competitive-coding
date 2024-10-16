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
vector<vector<int>> level_order(TreeNode* root){
    queue<pair<int,TreeNode*>> q;
    map<int,vector<int>> mpp;

    q.push({0,root});

    while(!q.empty()){
        TreeNode* temp = q.front().second;
        int curr_level = q.front().first;
        q.pop();

        mpp[curr_level].push_back(temp->val);
        
        if(temp->left){
            q.push({curr_level-1,temp->left});
        }
        if(temp->right){
            q.push({curr_level+1,temp->right});
        }
    }
    vector<vector<int>> output;
    for(auto it:mpp){
        vector<int> temp;
        // cout<<it.first<<": ";
        for(auto its:it.second){
            temp.push_back(its);
            // cout<<its<<" ";
        }
        output.push_back(temp);
        // cout<<endl;
    }

    return output;
} 

int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    root->right->left->right->left = new TreeNode(10);

    // call your functions here 
    vector<vector<int>> output = level_order(root);
    for(auto it:output){
        for(auto its:it){
            cout<<its<<" ";
        }
        cout<<endl;
    }

    return 0;
}