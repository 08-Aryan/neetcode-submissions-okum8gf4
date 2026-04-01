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
    int finder(TreeNode* root,int &res){
        if(!root){
            return 0;
        }
        int left = max(finder(root->left,res),0);
        int right = max(finder(root->right,res),0);
        res = max(left+right+root->val,res);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        finder(root,res);
        return res;

    }
};
