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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "N,";
        }
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(!top){
                ans += "N,";
            }
            else{
                ans += to_string(top->val) + ",";
                q.push(top->left);
                q.push(top->right);
            }
        }
        return ans;
    }
    
    // Decodes your encoded data to tree.
    string finder(string data, int &l){
        int r = l;
        int n = data.size();
        while(r<n && data[r]!=','){
            r++;
        }
        string sub = data.substr(l,r-l);
        l = r+1;
        return sub;
    }
    TreeNode* deserialize(string data) {
        int l = 0;
        int n = data.size();
        queue<TreeNode*> q;
        string val = finder(data,l);
        if(val=="N"){
            return nullptr;
        }
        TreeNode * root = new TreeNode(stoi(val));
        q.push(root);
        while(l<n){
            TreeNode* node = q.front();
            q.pop();
            val = finder(data,l);
            if(val != "N"){
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            val = finder(data,l);
            if(val != "N"){
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }

        }
        return root;
    }
};
