class Solution {
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(auto &d:dir){
                int nr = row+d[0];
                int nc = col + d[1];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc]!=INT_MAX){
                    continue;
                }
                grid[nr][nc] = grid[row][col]+1;
                q.push({nr,nc});
            }
            
        }
    }
};
