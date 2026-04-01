class DSU{
    vector<int> parent;
    vector<int> size;
    int components;
    public:
    DSU(int n){
        components = n;
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        size.resize(n,1);
    }
    int findP(int x){
        int par = parent[x];
        if(par == x){
            return x;
        }
        return parent[x] = findP(par);
    }
    void unionBySize(int x, int y){
        int par1 = findP(x),par2 = findP(y);
        if(par1 == par2){
            return;
        }
        else{
            components--;
            if(size[par1] < size[par2]){
                size[par2] += size[par1];
                parent[par1] = par2;
            }
            else{
                size[par1] += size[par2];
                parent[par2] = par1;
            }
        }
        return;
    }
    int findComp(){
        return components;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto &edge:edges){
            dsu.unionBySize(edge[0],edge[1]);
        }
        return dsu.findComp();
    }
};
