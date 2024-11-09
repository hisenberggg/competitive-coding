#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        TreeNode* left, *right;
        int val;
    TreeNode(int value){
        this->val = value;
        left = right = NULL;
    }
};

bool checkBST(TreeNode* root){
    
}

int main()
{
    // TreeNode* root = new TreeNode(10);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(15);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(8);
    // root->right->right = new TreeNode(7);

    // TreeNode* root = new TreeNode(10);
    // root->left = new TreeNode(11);
    // root->right = new TreeNode(9);

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(3);

    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(17);

    int maxsize = 1;
    int leftmin = INT_MIN, rightmax = INT_MAX;
    vector<int> output = largestBST(root);

    cout<<"Max size of BST is: "<<output[2];
    return 0;
}
