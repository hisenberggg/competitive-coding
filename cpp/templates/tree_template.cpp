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
 

    return 0;
}