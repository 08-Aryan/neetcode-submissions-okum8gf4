/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node *node,unordered_map<Node *,Node *> & copied){
        if(!node){
            return NULL;
        }
        if(copied.count(node)){
            return copied[node];
        }
        Node *root = new Node(node->val);

        copied[node] = root;
        for(auto &neighbor :node->neighbors){
            Node* copy = dfs(neighbor,copied);
            root->neighbors.push_back(copy);
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        unordered_map <Node*,Node*> copied;
        return dfs(node,copied);
        
    }
};
