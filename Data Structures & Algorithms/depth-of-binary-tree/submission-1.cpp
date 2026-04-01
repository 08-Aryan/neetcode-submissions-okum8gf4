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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(root){
            q.push({root,1});
        }
        int ans = 0;
        while(q.size()){

            int n = q.size();
            while(n>0){
                auto curr = q.front();
                q.pop();
                int depth = curr.second;
                ans = max(ans,depth);
                TreeNode* node = curr.first;
                if(node->left){
                    q.push({node->left,depth+1});
                }
                if(node->right){
                    q.push({node->right,depth+1});
                }
                n--;

                
            }
        }
        return ans;
        
    }
};
