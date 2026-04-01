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
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int count = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,INT_MIN});
        while(!q.empty()){
            auto [curr,maxima] = q.front();
            q.pop();
            if(curr->val >= maxima){
                count++;
                maxima = curr->val;
            }
            if(curr->left){
                q.push({curr->left,maxima});
            }
            if(curr->right){
                q.push({curr->right,maxima});
            }
        }
        return count;
    }
};
