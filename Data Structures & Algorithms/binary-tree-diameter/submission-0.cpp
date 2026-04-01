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
        int diam = 0;
        maxPath(root,diam);
        return diam;
        
    }
};
