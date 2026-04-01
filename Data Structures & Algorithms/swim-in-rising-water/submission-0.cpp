class Solution {
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    // Using dijikstra as we just to need find the path with minimum max
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        set<pair<int,int>> visited;
        //[elevation,r,c]
        minHeap.push({grid[0][0],0,0});
        visited.insert({0,0});
        int t = 0;
        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int r = curr[1],c = curr[2];
            t = curr[0];
            if(r == N-1 && c== N-1){
                return t;
            }
            for(const auto &d:dir){
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited.count({nr,nc})){
                    continue;
                }
                minHeap.push({max(t,grid[nr][nc]),nr,nc});
                visited.insert({nr,nc});
            }
        }
        // returned when not possible to reach end
        return N*N;



    }
};
