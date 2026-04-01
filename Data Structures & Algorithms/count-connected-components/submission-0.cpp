class DSU{
    vector<int> parent;
    vector<int> size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findP(int x){
        if(parent[x]!=x){
            parent[x]=findP(parent[x]);
        }
        return parent[x];
    }
    bool Union(int x,int y){
        int px = findP(x);
        int py = findP(y);
        if(px==py){
            return false;
        }
        if(size[px]>=size[py]){
            size[px] += size[py];
            parent[py]=px;

        }
        else {
            size[py] += size[px];
            parent[px]= py;
        }
        return true;

    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n;
        for(auto edge:edges){
            if(dsu.Union(edge[0],edge[1])){
                res--;
            }
        }
        return res;

    }
};
