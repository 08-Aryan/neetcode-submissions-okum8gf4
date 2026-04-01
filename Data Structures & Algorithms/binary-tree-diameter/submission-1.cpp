/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPath(TreeNode* root,int &diam){
        if(!root){
            return 0;
        }
        int left = maxPath(root->left,diam);
        int right = maxPath(root->right,diam);
        diam = max(left+right,diam);
        return 1 + max(left,right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*,pair<int,int>> mp;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode * top = stk.top();
            if(top->left && mp.find(top->left)==mp.end()){
                stk.push(top->left);
            }
            else if(top->right && mp.find(top->right)==mp.end()){
                stk.push(top->right);
            }
            else{
                stk.pop();
                auto [leftheight,leftdiameter]=mp[top->left];
                auto [rightheight,rightdiameter]=mp[top->right];
                int height = max(leftheight,rightheight)+1;
                int diameter = max(leftheight+rightheight,max(leftdiameter,rightdiameter));
                mp[top]={height,diameter};
            }
        }
        return mp[root].second;
        
    }
};
