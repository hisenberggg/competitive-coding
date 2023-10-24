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
typedef TreeNode tn; 
int maxlevel = -1;
// write your functions here 
void leftview(tn *root,int level){
    if(root == NULL) return;
    if(level>maxlevel){
        cout<<root->val<<"\n";
        maxlevel = level;
    }
    leftview(root->left,level+1);
    leftview(root->right,level+1);
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
    leftview(root,0);

    return 0;
}