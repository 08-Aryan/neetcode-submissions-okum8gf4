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
    bool ValidBST(TreeNode* root,long lb,long ub){
        if(!root){
            return true;
        }
        bool left=true,right = true;
        if(root->left){
            left = ValidBST(root->left,lb,root->val);
        }
        if(root->right){
            right = ValidBST(root->right,root->val,ub);
        }
        if(root->val > lb && root->val < ub){
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return ValidBST(root,(long)INT_MIN-1,(long)INT_MAX+1);
    }
};
