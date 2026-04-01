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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            if(top->left){
                stk.push(top->left);
            }
            if(top->right){
                stk.push(top->right);
            }
            TreeNode* temp = top->left;
            top->left = top->right;
            top->right = temp;
        }
        return root;
    }
};