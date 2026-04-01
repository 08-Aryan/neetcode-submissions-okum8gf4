class DSU {
    
    vector<int> parent;
    vector<int> size;
    public:
    DSU(int n){
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        size.resize(n,1);
    }
    int findP(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=findP(parent[x]);
    }
    bool Union(int x,int y){
        int p1 = findP(x);
        int p2 = findP(y);
        // When already in same
        if(p1==p2){
            return false;
        }
        if(size[p1] < size[p2]){
            parent[p1] = p2;
            size[p2] += size[p1];
        }
        else{
            parent[p2]= p1;
            size[p1] += size[p2];
        }
        return true;
    }
};

class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU graph(edges.size());
        for(auto edge:edges){
            if(!graph.Union(edge[0],edge[1])){
                return vector<int> {edge[0],edge[1]};
            }
        }
        return {};

    }
};
