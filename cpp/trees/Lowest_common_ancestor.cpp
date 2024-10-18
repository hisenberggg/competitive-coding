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
bool getpath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
    if(root == NULL){
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


TreeNode* LCA_bruteforce(TreeNode* root, TreeNode* p, TreeNode* q){
    vector<TreeNode*> pathp;
    getpath(root,p,pathp);
    vector<TreeNode*> pathq;
    getpath(root,q,pathq);

    int n = pathp.size();
    int m = pathq.size();

    TreeNode* ans = NULL;
    for(int i=0;i<min(n,m);i++){
        if(pathp[i]->val == pathq[i]->val){
            ans = pathp[i];
        }
        else{
            break;
        }
    }
    return ans;
}

TreeNode* LCA_optimal(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL){
        return NULL;
    }
    if(root == p || root == q){
        return root;
    }

    TreeNode* leftnode = LCA_optimal(root->left,p,q);
    TreeNode* rightnode = LCA_optimal(root->right,p,q);

    if(leftnode==NULL){
        return rightnode;
    }
    else if(rightnode==NULL){
        return leftnode;
    }
    else{
        return root;
    }
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
    TreeNode* p = root->left->left;
    TreeNode* q = root->left->right->right;
    // TreeNode* output = LCA_bruteforce(root, p, q);
    TreeNode* output = LCA_optimal(root, p, q);
    cout<<"LCA: "<<output->val;

    return 0;
}