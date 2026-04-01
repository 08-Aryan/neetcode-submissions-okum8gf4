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
    void ksmallest(TreeNode* root,int k,int &count,int &smallest){
        if(!root){
            return;
        }
        ksmallest(root->left,k,count,smallest);
        count++;
        if(k==count){
            smallest = root->val;
            return;
        }
        ksmallest(root->right,k,count,smallest);

    }
    int kthSmallest(TreeNode* root, int k) {
        int smallest = 0;
        int count = 0;
        ksmallest(root,k,count,smallest);
        return smallest;
    }
};
