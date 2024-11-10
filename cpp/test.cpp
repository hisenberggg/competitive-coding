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
// q : 
// temp 8:0
// lvl map 0:10,8 , -1:5, 1:15, -2:1
vector<int> levelOrderTraversal(TreeNode* root){
    queue<tuple<TreeNode*, int, int>> q;
    map<int,map<int,set<int>>> level_map;

    q.push({root,0,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        auto [temp, level, vlevel] = it;

        level_map[level][vlevel].insert(temp->val);

        if(temp->left){
            q.push({temp->left,level-1,vlevel+1});
        }
        if(temp->right){
            q.push({temp->right,level+1, vlevel+1});
        }
    }
    vector<int> output;
    for(auto it:level_map){
        for(auto its:it.second){
            output.insert(output.end(),its.second.begin(),its.second.end());
            // for(auto itss:its.second){
            //     output.push_back(itss);
            // }
        }
    }
    return output;
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(7);

    vector<int> output = levelOrderTraversal(root);
    for(auto it:output){
        cout<<it<<" ";
    }
    return 0;
}
