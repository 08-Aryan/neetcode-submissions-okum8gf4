class Solution {
public:
    vector<vector<int>> matrixmaker(vector<vector<int>> &edges,int n){
        vector<vector<int>> adj(n);
        for(vector<int> edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjmat = matrixmaker(edges,n);
        queue<pair<int,int>> q;
        q.push({0,-1});
        vector<bool> visited(n,false);
        visited[0]=true;
        while(!q.empty()){
            auto [node,parent] = q.front();
            q.pop();
            for(auto nie:adjmat[node]){
                if(nie == parent){
                    continue;
                }
                if(visited[nie]==true){
                    return false;
                }
                visited[nie]=true;
                q.push({nie,node});
                
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
