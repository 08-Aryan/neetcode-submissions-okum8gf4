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
    unordered_map<int , int> pos;   
    int preind = 0;
    TreeNode* treebuilt(vector<int>& preorder,int l,int r){
        if(l>r){
            return NULL;
        }
        int val = preorder[preind];
        preind++;
        int mid = pos[val];
        TreeNode* root = new TreeNode(val);
        root->left = treebuilt(preorder,l,mid-1);
        root->right = treebuilt(preorder,mid+1,r);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        for(int i = 0;i<n;i++){
            pos[inorder[i]]= i;
        }
        return treebuilt(preorder,0,n-1);

    }
};
