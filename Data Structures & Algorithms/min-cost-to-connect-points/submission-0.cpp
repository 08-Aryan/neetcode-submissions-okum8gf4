class DSU{
    vector<int> Parent,Size;
    public:
    DSU(int n){
        Parent.resize(n+1);
        Size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            Parent[i]=i;
        }
    }
    int find(int x){
        int root = x;
        while(root!=Parent[root]){
            root = Parent[root];
        }
        while(x != root){
            int next = Parent[x];
            Parent[x] = root;
            x = next;          
        }
        return root;
    }
    bool Union(int x,int y){
        int px = find(x),py = find(y);
        if(py==px)return false;
        else{
        if(Size[px] < Size[py]){
            Size[py] += Size[px];
            Parent[px] = py;
        }
        else{
            Size[px] += Size[py];
            Parent[py] = px;
        }
        return true;
        }
    }
};

class Solution {
    vector<vector<int>>edges;
public:
    int mandist(vector<int>&left,vector<int> &right){
        return abs(left[0]-right[0]) + abs(left[1]-right[1]);
    }
    void finddistances(vector<vector<int>>& points){
        int left = 0;
        int n = points.size();
        while(left<n){
            int right = left+1;
            while(right<n){
                int dist = mandist(points[left],points[right]);
                edges.push_back({dist,left,right});
                right++;
            }
            left++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        finddistances(points);
        sort(edges.begin(),edges.end(),[](auto &a,auto &b){return a[0]<b[0];});
        int ans = 0;
        DSU dsu(points.size());
        for(auto &edge:edges){
            if(dsu.Union(edge[1],edge[2])){
                ans+=edge[0];
            }
        }
        return ans;

        // Kruskal algo




    }
};
